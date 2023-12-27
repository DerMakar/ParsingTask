#include "document.h"

using namespace std::literals;

int main(int argc, char* argv[]) {
	if (argc != 3 ) {
		std::cerr << "Unvalid arguments ([program name] [input_file] [output_file])";
		return -1;
	}

	try {
		rstyle::Document document(argv[1]);
		document.Load();
		document.Print(argv[2]);
	}
	catch (const rstyle::ParsingError& exc) {
		std::cerr << exc.what();
	}	
	return 0;
}