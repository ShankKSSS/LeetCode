class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        // Track which numbers (0-8) are used in each row, column, and 3x3 block
        bool row[9][9] = {false};
        bool col[9][9] = {false}; 
        bool block[3][3][9] = {false};
        
        // Store positions of all empty cells
        vector<pair<int, int>> emptyCells;
        bool solved = false;
        
        // Initialize tracking arrays and collect empty cells
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    emptyCells.push_back({i, j});
                } else {
                    int digit = board[i][j] - '1'; // Convert '1'-'9' to 0-8
                    row[i][digit] = true;
                    col[j][digit] = true;
                    block[i / 3][j / 3][digit] = true;
                }
            }
        }
        
        // Backtracking function
        function<void(int)> backtrack = [&](int cellIndex) {
            // Base case: all empty cells filled
            if (cellIndex == emptyCells.size()) {
                solved = true;
                return;
            }
            
            int currentRow = emptyCells[cellIndex].first;
            int currentCol = emptyCells[cellIndex].second;
            int blockRow = currentRow / 3;
            int blockCol = currentCol / 3;
            
            // Try digits 1-9 (represented as 0-8 internally)
            for (int digit = 0; digit < 9; ++digit) {
                // Check if digit can be placed at current position
                if (!row[currentRow][digit] && 
                    !col[currentCol][digit] && 
                    !block[blockRow][blockCol][digit]) {
                    
                    // Place the digit
                    row[currentRow][digit] = true;
                    col[currentCol][digit] = true;
                    block[blockRow][blockCol][digit] = true;
                    board[currentRow][currentCol] = digit + '1';
                    
                    // Recursively solve next cell
                    backtrack(cellIndex + 1);
                    
                    // If solution found, stop backtracking
                    if (solved) return;
                    
                    // Backtrack: remove the digit
                    row[currentRow][digit] = false;
                    col[currentCol][digit] = false;
                    block[blockRow][blockCol][digit] = false;
                }
            }
        };
        
        // Start solving from first empty cell
        backtrack(0);
    }
};
