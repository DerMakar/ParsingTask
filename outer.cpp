#include "outer.h"

namespace rstyle {
    void PrintValue(const std::string& str, std::ostream& out, int indent_step) {
        using namespace std::literals;
        out << str << std::endl;
    }

    void PrintIndent(std::ostream& out, int indent_step) {
        for (int i = 0; i < indent_step; ++i) {
            out << ' ';
        }
    }

    void PrintNode(const Node& node, std::ostream& out, int indent_step) {
        out << node.GetId();
        out << ", ";
        out << node.GetParId();
        out << ", ";
        out << node.GetName();
        out << ", ";
        std::visit(
            [&out, indent_step](const auto& value) { PrintValue(value, out, indent_step); },
            node.GetValue());
    }

    void PrintValue(const List& list, std::ostream& out, int indent_step) {
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
            PrintNode(*node, out, indent_step + 2);
        }
    }
} //namespace rstyle