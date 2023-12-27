#pragma once
#include <fstream>
#include "node.h"
#include <iostream>
#include "outer.h"

namespace rstyle {
	class Document {
	public:
		Document();

		explicit Document(const std::string& file_name);

		void Print(const std::string& outfile) const;

		void Load();

		void SetRoot(std::unique_ptr<Node>& other);
		
	private:
		std::string file_name_;
		std::unique_ptr<Node> root_ = nullptr;

		static std::string Trim(std::string_view str);

		Node LoadNode(std::istream& input, int& id, int parent_id);

		Node LoadList(std::istream& input, std::string&& name, int& id, int parent_id);

		Node LoadString(std::istream& input, std::string&& name, int& id, int parent_id);
	};
} //namespace rstyle