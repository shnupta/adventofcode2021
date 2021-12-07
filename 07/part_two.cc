#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <limits>

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

	int mean = std::reduce(positions.begin(), positions.end()) / positions.size();
	std::cout << "Mean value: " << mean << std::endl;
	
	int bestPosition;
	int bestFuelCost = std::numeric_limits<int>::max();
	for (int i = 0; i < positions.size(); i++) {
		int totalFuelCost = std::accumulate(positions.begin(), positions.end(), 0, [&](int sum, int pos) {
					return sum + (std::abs(pos - i) * (std::abs(pos - i) + 1)) / 2;
					});
		if (totalFuelCost < bestFuelCost) {
			bestPosition = i;
			bestFuelCost = totalFuelCost;
		}
	}

	std::cout << "Best position: " << bestPosition << std::endl;
	std::cout << "Best fuel cost: " << bestFuelCost << std::endl;

	return 0;
}
