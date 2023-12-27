#include "document.h"

namespace rstyle {
    Document::Document() = default;
    
    Document::Document(const std::string& file_name) 
        : file_name_(file_name){
	}

	void Document::Load() {
		std::ifstream input (file_name_);
		if (!input.is_open()) throw std::exception("no such infile");
		int id = 1;
		SetRoot(std::make_unique<Node> (LoadNode(input, id, 0)));
        input.get();
        if (!input.eof()) {
            std::string rest_of_data;
            while (input) {
                char c = input.get();
                rest_of_data += c;
            }
            throw ParsingError("Error: not full parsing. Rest of data: \"" + rest_of_data + "\"");
        }
	}

	void Document::Print(const std::string& outfile) const {
		std::ofstream output(outfile);
		if(!output.is_open()) throw std::exception("no such outfile");
		root_->PrintNode(output, 0);	}

    std::string Document::Trim(std::string_view str) {
        while (!str.empty() && (str.front() == ' ' || str.front() == '\t'
            || str.front() == '\n' || str.front() == '\r')) {
            str.remove_prefix(1);
        }
        while (!str.empty() && (str.back() == ' ' || str.back() == '\t'
            || str.back() == '\n' || str.back() == '\r')) {
            str.remove_suffix(1);
        }
        return std::string(str);
    }

    void Document::SetRoot(std::unique_ptr<Node>& other) {
        std::swap(other, root_);
    }

    Node Document::LoadList(std::istream& input, std::string&& name, int& id, int parent_id) {
        List result;
        int start_id = id;
        char c = 'a';
        input >> c;
        if (c != '{') {
            throw ParsingError("Error: Expected '{'");
        }
        input >> std::ws;
        c = input.peek();
        if(c == '{') throw ParsingError("Error: double '{'");
        while (c != '}') {
            input >> std::ws;
            result.push_back(std::make_shared<Node>(LoadNode(input, ++id, start_id)));
            input >> std::ws;
            c = input.peek();
            if (isalpha(c)) {
                continue;
            }
            else if (input.peek() != '}') {
                throw ParsingError("Error: Expected ' ' or '}'");
            }
        }
        input >> c;
        return Node(start_id, parent_id, std::move(name), std::move(result));
    }

    Node Document::LoadString(std::istream& input, std::string&& name, int& id, int parent_id)  {
        using namespace std::literals;
        std::string text;
        getline(input, text, '\"');
        if(text.empty()) throw ParsingError("Error: empty str_value");
        text = Trim(text); // if we need it
        return Node(id, parent_id, std::move(name), move(text));
    }

    Node Document::LoadNode(std::istream& input, int& id, int parent_id) {
        using namespace std::literals;
        std::string name;
        getline(input, name, '=');
        name = move(Trim(name));
        char c = 'a';
        input >> c;
        if (c == '{') {
            input.putback(c);
            return LoadList(input, move(name), id, parent_id);
        }
        else if (c == '"') {
            return LoadString(input, move(name), id, parent_id);
        }
        else {
            throw ParsingError("Неверный формат данных"s); // another check for empty file?
        }
    }
}//namespace rstyle
