#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

int main(int argc, char **argv) {
	std::string line;
	std::vector<int> positions;

	std::ifstream inputFile("input.txt");

	while (getline(inputFile, line)) {
		std::stringstream ss(line);
		int pos;
		while (ss >> pos) {
			positions.push_back(pos);
			ss.ignore(1);
		}
	}
	inputFile.close();

	std::sort(positions.begin(), positions.end());
	int median = positions[positions.size() / 2];
	int totalFuelCost = 0;
	std::for_each(positions.begin(), positions.end(), [&](int pos) {
			totalFuelCost += std::abs(pos - median);
			});

	std::cout << "Best position: " << median << std::endl;
	std::cout << "Total fuel cost: " << totalFuelCost << std::endl;

	return 0;
}
