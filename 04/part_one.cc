#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>

struct BingoNumber {
	int num;
	bool marked = false;
};

struct Board {
	std::vector<std::vector<BingoNumber>> board;
};

void SetNumsToDraw(std::vector<int> &numsToDraw, const std::string numsString) {
	std::stringstream ss(numsString);

	for (int i; ss >> i;) {
		numsToDraw.push_back(i);
		if (ss.peek() == ',')
			ss.ignore();
	}
}

void ReadBoardRow(std::vector<BingoNumber> &row, const std::string line) {
	std::stringstream ss(line);
	for (int i; ss >> i;) {
		BingoNumber bn;
		bn.num = i;
		row.push_back(bn);
		if (ss.peek() == ' ')
			ss.ignore();
	}
}

int main(int argc, char **argv) {
	std::string line;
	std::vector<int> numsToDraw;
	bool first = true;
	std::vector<Board> boards;

	std::ifstream inputFile("input.txt");

	while (getline(inputFile, line)) {
		if (first) {
			SetNumsToDraw(numsToDraw, line);
			continue;
		}
		if (line.empty()) continue;
		// Read in the board, we already have the first line if here
		Board b;
		std::vector<BingoNumber> row;
		ReadBoardRow(row, line);
		b.board.emplace_back(row);
		for (int i = 1; i < 5; i++) {
			std::vector<BingoNumber> row;
			ReadBoardRow(row, line);
			b.board.emplace_back(row);
		}
		boards.emplace_back(b);
	}

	// We have all boards, iterate through the numbers marking the boards and checking them

	inputFile.close();

	return 0;
}
