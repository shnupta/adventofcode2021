#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

int main(int argc, char **argv) {
	std::string line;

	std::ifstream inputFile("input.txt");

	while (getline(inputFile, line)) {
	}

	inputFile.close();

	return 0;
}
