#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv) {
	std::string line;

	std::ifstream inputFile("input.txt");

	int previous = 0;
	int current;
	bool first = true;
	int increaseCount = 0;
	while (getline(inputFile, line)) {
		current = atoi(line.c_str());
		if (!first && current > previous)
			increaseCount++;
		previous = current;
		first = false;
	}

	inputFile.close();

	std::cout << "Number of increases: " << increaseCount << std::endl;

	return 0;
}
