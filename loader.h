#pragma once
#include "node.h"
#include <iostream>

namespace rstyle {
	std::string Trim(std::string_view str);

	Node LoadNode(std::istream& input, int& id);

	Node LoadList(std::istream& input, std::string&& name, int& id);

	Node LoadString(std::istream& input, std::string&& name, int& id);
}// nmaespace rstyle