#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>
#include <bitset>
#include <algorithm>

char getMostCommon(const std::vector<std::string> &vec, const int index) {
	unsigned int oneCount = 0;
	unsigned int zeroCount = 0;
	for (int i = 0; i < vec.size(); i++) { 
		if (vec[i][index] == '1')
			oneCount++;
		else
			zeroCount++;
	}
	return oneCount >= zeroCount ? '1' : '0';
}

char getLeastCommon(const std::vector<std::string> &vec, const int index) {
	unsigned int oneCount = 0;
	unsigned int zeroCount = 0;
	for (int i = 0; i < vec.size(); i++) { 
		if (vec[i][index] == '1')
			oneCount++;
		else
			zeroCount++;
	}
	return zeroCount <= oneCount ? '0' : '1';
}

int main(int argc, char **argv) {
	std::string line;
	std::vector<std::string> oxygen;
	std::vector<std::string> co2;

	std::ifstream inputFile("input.txt");

	while (getline(inputFile, line)) {
		oxygen.push_back(line);
		co2.push_back(line);
	}

	int col = 0;
	while (oxygen.size() > 1) {
		int ones = 0;
		int zeroes = 0;
		for (int row = 0; row < oxygen.size(); row++) {
			if (oxygen[row][col] == '0')
				zeroes++;
			else
				ones++;
		}
		char max = (ones >= zeroes ? '1' : '0');
		for (int row = oxygen.size() - 1; row >= 0; row--) {
			if (oxygen[row][col] != max)
				oxygen.erase(oxygen.begin() + row);
		}
		col++;
	}

	col = 0;
	while (co2.size() > 1) {
		int ones = 0;
		int zeroes = 0;
		for (int row = 0; row < co2.size(); row++) {
			if (co2[row][col] == '0')
				zeroes++;
			else
				ones++;
		}
		char min = (zeroes <= ones ? '0' : '1');
		for (int row = co2.size() - 1; row >= 0; row--) {
			if (co2[row][col] != min)
				co2.erase(co2.begin() + row);
		}
		col++;
	}

	unsigned int oxygenRating = std::stoi(oxygen[0], nullptr, 2);
	unsigned int co2Rating = std::stoi(co2[0], nullptr, 2);

	std::cout << "Oxygen rating: " << oxygenRating << std::endl;
	std::cout << "CO2 rating: " << co2Rating << std::endl;
	std::cout << "Life support: " << oxygenRating * co2Rating << std::endl;

	inputFile.close();

	return 0;
}
