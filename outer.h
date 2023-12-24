#pragma once
#include "node.h"
#include <iostream>

namespace rstyle {
    template <typename Value>
    void PrintValue(const Value& value, std::ostream& out, int indent_step = 0) {
        out << value;
    }
    
    void PrintValue(const std::string& str, std::ostream& out, int indent_step);

    void PrintIndent(std::ostream& out, int indent_step);

    void PrintNode(const Node& node, std::ostream& out, int indent_step);

    void PrintValue(const List& list, std::ostream& out, int indent_step);
    
} //namespace rstyle
