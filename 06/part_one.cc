#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

struct LaternFish {
	int timer;

	LaternFish() : timer(6) {}
	LaternFish(int age) : timer(age) {}
	void PassDay(std::vector<LaternFish> &population) {
		timer--;
		if (timer < 0) {
			timer = 6;
			population.emplace_back<LaternFish>(8);
		}
	}
};

int main(int argc, char **argv) {
	std::string line;
	std::vector<LaternFish> fish;

	std::ifstream inputFile("input.txt");

	while (getline(inputFile, line)) {
		std::stringstream ss(line);
		int age;
		while (ss >> age) {
			fish.emplace_back<LaternFish>(age);
			ss.ignore(1);
		}
	}
	inputFile.close();

	for (int i = 0; i < 80; i++) {
		int currentSize = fish.size();
		for (int j = 0; j < currentSize; j++) {
			fish[j].PassDay(fish);
		}
	}

	std::cout << fish.size() << std::endl;

	return 0;
}
