#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

int main(int argc, char **argv) {
	std::string line;
	std::string direction;
	int value;
	int forward = 0;
	int depth = 0;

	std::ifstream inputFile("input.txt");

	while (getline(inputFile, line)) {
		std::string temp;
		std::istringstream iss(line);
		iss >> direction;
		iss >> temp;
		value = atoi(temp.c_str());
		if (direction == "forward")
			forward += value;
		else if (direction == "down")
			depth += value;
		else
			depth -= value;
	}

	inputFile.close();

	std::cout << "Depth: " << depth << std::endl;
	std::cout << "Horizontal: " << forward << std::endl;
	std::cout << "Multiplied: " << depth * forward << std::endl;

	return 0;
}
