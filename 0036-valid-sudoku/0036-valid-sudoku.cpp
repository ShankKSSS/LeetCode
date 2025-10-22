#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Use 3 boolean arrays for rows, columns, and boxes
        bool rows[9][9] = {false};
        bool cols[9][9] = {false};
        bool boxes[9][9] = {false};

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') continue;
                int num = board[i][j] - '1';  // map '1'-'9' to 0-8
                int boxIndex = (i / 3) * 3 + (j / 3);

                // If already seen in row, column or box, invalid
                if (rows[i][num] || cols[j][num] || boxes[boxIndex][num]) {
                    return false;
                }
                rows[i][num] = true;
                cols[j][num] = true;
                boxes[boxIndex][num] = true;
            }
        }
        return true;
    }
};
