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

    void Node::PrintValue(std::ostream& out, int indent_step) const {
        if (std::holds_alternative<std::string>(value_)) {
            PrintString(std::get<std::string>(value_), out, indent_step);
        }
        else if (std::holds_alternative<List>(value_)) {
            PrintList(std::get<List>(value_), out, indent_step);
        }
    }

    void Node::PrintString(const std::string& str, std::ostream& out, int indent_step) const {
        using namespace std::literals;
        out << str << std::endl;
    }

    void Node::PrintIndent(std::ostream& out, int indent_step) const {
        for (int i = 0; i < indent_step; ++i) {
            out << ' ';
        }
    }

    void Node::PrintNode(std::ostream& out, int indent_step) const {
        out << GetId();
        out << ", ";
        out << GetParId();
        out << ", ";
        out << GetName();
        out << ", ";
        PrintValue(out, indent_step);
    }

    void Node::PrintList(const List& list, std::ostream& out, int indent_step) const {
        using namespace std::literals;
        bool IsFirst = true;
        for (const auto& node : list) {
            if (!IsFirst) {
                out << ", "s;

            }
            else {
                IsFirst = false;
            }
            out << node->GetId();
        }
        out << std::endl;
        for (const auto& node : list) {
            PrintIndent(out, indent_step + 2);
            node->PrintNode(out, indent_step + 2);
        }
    }
}// namespace rstyle
