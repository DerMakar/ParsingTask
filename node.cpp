#include "node.h"

namespace rstyle {
	int Node::GetId() const {
		return id_;
	}

	int Node::GetParId() const {
		return parent_id_;
	}

	const std::string& Node::GetName() const {
		return name_;
	}
	
	const Node::Value& Node::GetValue() const {
		return value_;
	}	
}// namespace rstyle
