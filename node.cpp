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

	bool Node::IsString() const {
		return std::holds_alternative<std::string>(value_);
	}

	bool Node::IsList() const {
		return std::holds_alternative<List>(value_);
	}

	bool Node::IsNull() const {
		return std::holds_alternative<std::nullptr_t>(value_);
	}

	const std::string& Node::AsString() const {
		using namespace std::literals;
		if (IsString()) {
			return std::get<std::string>(value_);
		}
		throw std::logic_error("no string in Node"s);
	}

	const List& Node::AsList() const {
		using namespace std::literals;
		if (IsList()) {
			return std::get<List>(value_);
		}
		throw std::logic_error("no List in Node"s);
	}
}// namespace rstyle
