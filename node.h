#pragma once
#include <vector>
#include <exception>
#include <stdexcept>
#include <string>
#include <variant>
#include <memory>


namespace rstyle {
	class Node;
	
	using List = std::vector<std::shared_ptr<Node>>;
		
	class ParsingError : public std::runtime_error {
	public:
		using runtime_error::runtime_error;
	};

	class Node {
	public:
		using Value = std::variant<std::nullptr_t, std::string, List>;

		Node() = default;

		template <typename V>
		Node(V value)
			: value_(value){
		}

		template <typename V>
		Node(int id, const std::string& name,const V& value)
			: id_(id)
			, name_(name)
			, value_(value){
		}

		int GetId() const;

		const std::string& GetName() const;

		const Value& GetValue() const;

		bool IsString() const;

		bool IsList() const;

		bool IsNull() const;

		const std::string& AsString() const;

		const List& AsList() const;

	private:
		int id_ = -1;
		std::string name_;
		Value value_;
	};
} // namespace rstyle
