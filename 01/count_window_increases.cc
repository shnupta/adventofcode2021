#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv) {
	std::string line;
	int window[3];

	std::ifstream inputFile("input.txt");

	int previousWindowSum = 0;
	int currentWindowSum = 0;
	int insertedCount = 0;
	int increaseCount = 0;
	bool first = true;
	while (getline(inputFile, line)) {
		const int current = atoi(line.c_str());
		if (insertedCount == 3) { // Shift values in the window down and add current to end
			first = false;
			previousWindowSum = currentWindowSum;
			currentWindowSum -= window[0];
			window[0] = window[1];
			window[1] = window[2];
			window[2] = current;
		} else {
			window[insertedCount] = current;
			insertedCount++;
		}
		currentWindowSum += current;
		std::cout << "Current window sum: " << currentWindowSum << std::endl;
		std::cout << "Previous window sum: " << previousWindowSum << std::endl;

		if (!first && currentWindowSum > previousWindowSum)
			increaseCount++;

	}

	inputFile.close();

	std::cout << "Number of window increases: " << increaseCount << std::endl;

	return 0;
}
