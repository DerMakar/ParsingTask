#include "document.h"

using namespace std::literals;

int main() {
	std::cout << "Enter infile name: "s;
	std::string file;
	std::cin >> file;
	rstyle::Document document(file);
	std::cout << "Enter outfile_name: "s;
	std::cin >> file;
	document.Print(file);
	return 0;
}