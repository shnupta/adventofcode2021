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

	int UnmarkedSum() {
		int sum = 0;
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (!board[i][j].marked) sum += board[i][j].num;
			}
		}
		return sum;
	}
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
		bn.marked = false;
		row.push_back(bn);
		if (ss.peek() == ' ')
			ss.ignore();
	}
}

void MarkBoards(std::vector<Board> &boards, const int num) {
	for (auto& b : boards) {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				std::cout << b.board[i][j].num << "(" << (b.board[i][j].marked ? "marked)" : "unmarked)") << ", ";
				if (b.board[i][j].num == num) {
					b.board[i][j].marked = true;
				}
			}
			std::cout << std::endl;
		}

		std::cout << std::endl << std::endl;
	}
}

// Returns index of board that won, -1 if no winning board
int CheckBoards(const std::vector<Board> &boards) {
	for (int b = 0; b < boards.size(); b++) {
		// Check rows
		for (int i = 0; i < 5; i++) {
			int j = 0;
			while (j < 5 && boards[b].board[i][j].marked) j++;
			if (j == 5) return b;
		}

		// Check columns
		for (int j = 0; j < 5; j++) {
			int i = 0;
			while (i < 5 && boards[b].board[i][j].marked) i++;
			if (i == 5) return b;
		}
	}

	return -1;
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
			first = false;
			continue;
		}
		if (line.empty()) continue;
		// Read in the board, we already have the first line if here
		Board b;
		std::vector<BingoNumber> row;
		ReadBoardRow(row, line);
		b.board.push_back(row);
		for (int i = 1; i < 5; i++) {
			std::vector<BingoNumber> row;
			getline(inputFile, line);
			ReadBoardRow(row, line);
			b.board.push_back(row);
		}
		boards.push_back(b);
	}

	std::cout << boards.size() << std::endl;

	// We have all boards, iterate through the numbers marking the boards and checking them
	for (int num : numsToDraw) {
		MarkBoards(boards, num);
		int winnerIndex = CheckBoards(boards);
		if (winnerIndex > -1) {
			std::cout << "Board " << winnerIndex << " is the winner!\n";
			std::cout << "Last number to be drawn: " << num << std::endl;
			std::cout << "Final score: " << boards[winnerIndex].UnmarkedSum() * num << std::endl;
			break;
		}
	}

	inputFile.close();

	return 0;
}
