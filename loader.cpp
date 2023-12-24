#include "loader.h"

namespace rstyle {
    std::string Trim(std::string_view str) {
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
    
   	Node LoadList(std::istream& input, std::string&& name, int& id) {
		List result;
        int start_id = id;
        char c = 'a';
        input >> c;
        if (c != '{') {
            throw ParsingError("Error: Expected '{'");
        }
        input >> std::ws;
        c = input.peek();
        while (c != '}') {
            input >> std::ws;
            result.push_back(std::make_shared<Node> (LoadNode(input, ++id)));
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
       	return Node(start_id, std::move(name), std::move(result));
	}

    Node LoadString(std::istream& input, std::string&& name, int& id) {
		using namespace std::literals;
        std::string text;
        getline(input, text, '\"');
        text = Trim(text);
        return Node(id, std::move(name), move(text));
	}

	Node LoadNode(std::istream& input, int& id) {
		using namespace std::literals;
        std::string name;
        getline(input, name, '=');
        name = move(Trim(name));
        char c = 'a';
        input >> c;
		if (c == '{') {
            input.putback(c);
            return LoadList(input, move(name), id);
        }
        else if (c == '"') {
            return LoadString(input, move(name), id);
        }
        else {
            throw ParsingError("Неверный формат данных"s);
        }
    }
	
}// nmaespace rstyle