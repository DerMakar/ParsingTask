#include "document.h"

namespace rstyle {
	Document::Document(const std::string& file_name) {
		Load(file_name);
	}

	void Document::Load(const std::string& file_name) {
		std::ifstream input (file_name);
		if (!input.is_open()) throw std::exception("no such infile");
		int id = 1;
		root_ = std::make_unique<Node> (LoadNode(input, id, 0));		
	}

	void Document::Print(const std::string& outfile) const {
		std::ofstream output(outfile);
		if(!output.is_open()) throw std::exception("no such outfile");
		PrintNode(*root_, output, 0);
	}


	const Node& Document::GetRoot() const {
		return *root_;
	}
}//namespace rstyle
