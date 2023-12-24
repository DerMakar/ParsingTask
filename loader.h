#pragma once
#include "node.h"
#include <iostream>

namespace rstyle {
	std::string Trim(std::string_view str);

	Node LoadNode(std::istream& input, int& id, int parent_id);

	Node LoadList(std::istream& input, std::string&& name, int& id, int parent_id);

	Node LoadString(std::istream& input, std::string&& name, int& id, int parent_id);
}// nmaespace rstyle