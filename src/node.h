#pragma once
#include <iostream>
#include <vector>
#include <exception>
#include <stdexcept>
#include <string>
#include <variant>
#include <memory>


namespace rstyle {
	class Node;
	
	using List = std::vector<std::shared_ptr<Node>>;
		
	class ParsingError : public std::exception {
	public:
		
		ParsingError()
			: message_("Неверный формат данных") {
		}
		
		const char* what() const override;
	private:
		const char* message_;
	};

	class Node {
	public:
		using Value = std::variant<std::nullptr_t, std::string, List>;

		Node() = default;

		template <typename V>
		Node(const V& value)
			: value_(value){
		}

		Node(const Node& other) = default;
		Node operator=(const Node& other) = delete;

		Node(Node&& other) = default;
		Node operator=(Node&& other) = delete;

		template <typename V>
		Node(int id, int parent_id, const std::string& name,const V& value)
			: id_(id)
			, parent_id_(parent_id)
			, name_(name)
			, value_(value){
		}

		int GetId() const;

		int GetParId() const;

		const std::string& GetName() const;

		const Value& GetValue() const;

		void PrintValue(std::ostream& out, int indent_step = 0) const;

		void PrintNode(std::ostream& out, int indent_step) const;
				
	private:
		int id_ = -1;
		int parent_id_ = -1;
		std::string name_;
		Value value_;

		void PrintString(const std::string& str, std::ostream& out, int indent_step) const;

		void PrintList(const List& list, std::ostream& out, int indent_step) const;

		void PrintIndent(std::ostream& out, int indent_step) const;
	};
		
} // namespace rstyle
