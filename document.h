#pragma once
#include <fstream>
#include "loader.h"
#include "outer.h"

namespace rstyle {
	class Document {
	public:
		explicit Document(const std::string& file_name);

		void Print(const std::string& outfile) const;
		
	private:
		std::unique_ptr<Node> root_ = nullptr;

		void Load(const std::string& file_name);
	};
} //namespace rstyle