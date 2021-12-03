#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>
#include <bitset>

int main(int argc, char **argv) {
	std::string line;
	std::vector<unsigned int> onesCount(12);
	std::vector<unsigned int> zerosCount(12);

	std::ifstream inputFile("input.txt");

	while (getline(inputFile, line)) {
		for (int i = 0; i < line.length(); i++) {
			if (line[i] == '1') {
				onesCount[i]++;
			} else {
				zerosCount[i]++;
			}
		}
	}

	std::ostringstream ossOnes;
	// Convert all but the last element to avoid a trailing ","
	std::copy(onesCount.begin(), onesCount.end()-1,
			std::ostream_iterator<int>(ossOnes, ","));

	// Now add the last element with no delimiter
	ossOnes << onesCount.back();

	std::ostringstream ossZeros;
	// Convert all but the last element to avoid a trailing ","
	std::copy(zerosCount.begin(), zerosCount.end()-1,
			std::ostream_iterator<int>(ossZeros, ","));

	// Now add the last element with no delimiter
	ossZeros << zerosCount.back();

	std::cout << "Ones count: " << ossOnes.str() << std::endl;
	std::cout << "Zeros count: " << ossZeros.str() << std::endl;
	
	unsigned int gammaRate = 0;
	unsigned int epsilonRate = 0;
	for (int i = 0; i < 12; i++) {
		gammaRate |= (onesCount[i] > zerosCount[i] ? 0b1 : 0b0) << (12 - (i+1));
		epsilonRate |= (onesCount[i] < zerosCount[i] ? 0b1 : 0b0) << (12 - (i+1));
	}

	unsigned int powerConsumption = gammaRate * epsilonRate;

	std::cout << "Gamma rate: " << std::bitset<12>(gammaRate) << " ( " << gammaRate << " )" << std::endl;
	std::cout << "Epsilon rate: " << std::bitset<12>(epsilonRate) << " ( " << epsilonRate << " )" << std::endl;

	std::cout << "Power consumption: " << powerConsumption << std::endl;

	inputFile.close();

	return 0;
}
