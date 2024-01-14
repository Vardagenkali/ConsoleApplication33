#include <iostream>
#include <vector>

class EightQueens {
private:
    const int boardSize = 8;
    std::vector<std::vector<int>> chessboard;

public:
    EightQueens() : chessboard(boardSize, std::vector<int>(boardSize, 0)) {}

    bool isSafe(int row, int col) const {
        for (int i = 0; i < row; ++i) {
            if (chessboard[i][col] == 1) {
                return false;
            }
        }

        for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
            if (chessboard[i][j] == 1) {
                return false;
            }
        }

        for (int i = row, j = col; i >= 0 && j < boardSize; --i, ++j) {
            if (chessboard[i][j] == 1) {
                return false;
            }
        }

        return true;
    }

    bool solveQueens(int row) {
        if (row == boardSize) {
            return true;
        }

        for (int col = 0; col < boardSize; ++col) {
            if (isSafe(row, col)) {
                chessboard[row][col] = 1;

                if (solveQueens(row + 1)) {
                    return true;
                }

                chessboard[row][col] = 0;
            }
        }

        return false;
    }

    void printSolution() const {
        for (int i = 0; i < boardSize; ++i) {
            for (int j = 0; j < boardSize; ++j) {
                std::cout << "(" << i << "," << j << ") ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    EightQueens eightQueens;

    if (eightQueens.solveQueens(0)) {
        std::cout << "8 Queens Solution:\n";
        eightQueens.printSolution();
    }
    else {
        std::cout << "Solution not found!\n";
    }

    return 0;
}
