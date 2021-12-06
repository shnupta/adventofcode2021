#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <unordered_map>

int main(int argc, char **argv) {
	std::string line;
	std::unordered_map<int, std::unordered_map<int, int>> coords;

	std::ifstream inputFile("input.txt");

	while (getline(inputFile, line)) {
		std::stringstream ss(line);
		int x1, y1, x2, y2;
		ss >> x1;
		ss.ignore(1);
		ss >> y1;
		ss.ignore(4);
		ss >> x2;
		ss.ignore(1);
		ss >> y2;

		if (x1 == x2 && y1 == y2) {
			coords[x1][y1]++;
			continue;
		}

		/* std::cout << "VENT: " << x1 << "," << y1 << " -> " << x2 << "," << y2 << std::endl; */

		// Vertical line (add all inbetween y values)
		if (x1 == x2) {
			for (int y = y1; (y1 > y2 ? y >= y2 : y <= y2); (y1 > y2 ? y-- : y++)) {
				/* std::cout << "Incrementing " << x1 << "," << y << std::endl; */
				coords[x1][y]++;
			}
		} else if (y1 == y2) { // Horizontal line (add all inbetween x values)
			for (int x = x1; (x1 > x2 ? x >= x2 : x <= x2); (x1 > x2 ? x-- : x++)) {
				/* std::cout << "Incrementing " << x << "," << y1 << std::endl; */
				coords[x][y1]++;
			}
		} else { // Diagonal
			int y = y1;
			for (int x = x1; (x1 > x2 ? x >= x2 : x <= x2); (x1 > x2 ? x-- : x++)) {
				coords[x][y]++;
				y1 > y2 ? y-- : y++;
			}
		}
	}

	int crossoverCount = 0;
	for (auto i = coords.begin(); i != coords.end(); i++) {
		for (auto j = i->second.begin(); j != i->second.end(); j++) {
			if (j->second > 1) crossoverCount++; 
		}
	}

	std::cout << "Crossover count: " << crossoverCount << std::endl;
	inputFile.close();

	return 0;
}
