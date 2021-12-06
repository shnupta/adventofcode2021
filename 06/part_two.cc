#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

int main(int argc, char **argv) {
	std::string line;
	std::vector<long> fish(9); // Internal timers 0-8

	std::ifstream inputFile("input.txt");

	while (getline(inputFile, line)) {
		std::stringstream ss(line);
		int age;
		while (ss >> age) {
			fish[age]++;
			ss.ignore(1);
		}
	}
	inputFile.close();

	for (int i = 0; i < 256; i++) {
		std::rotate(fish.begin(), fish.begin() + 1, fish.end());
		fish[6] += fish[8];
	}

	long fishCount = std::accumulate(fish.cbegin(), fish.cend(), 0l);
	std::cout << fishCount << std::endl;

	return 0;
}
