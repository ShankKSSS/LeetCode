class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        
        bool row[9][9] = {false};
        bool col[9][9] = {false}; 
        bool block[3][3][9] = {false};
        
        
        vector<pair<int, int>> emptyCells;
        bool solved = false;
        
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    emptyCells.push_back({i, j});
                } else {
                    int digit = board[i][j] - '1'; 
                    row[i][digit] = true;
                    col[j][digit] = true;
                    block[i / 3][j / 3][digit] = true;
                }
            }
        }
        
        
        function<void(int)> backtrack = [&](int cellIndex) {
           
            if (cellIndex == emptyCells.size()) {
                solved = true;
                return;
            }
            
            int currentRow = emptyCells[cellIndex].first;
            int currentCol = emptyCells[cellIndex].second;
            int blockRow = currentRow / 3;
            int blockCol = currentCol / 3;
            
            
            for (int digit = 0; digit < 9; ++digit) {
                
                if (!row[currentRow][digit] && 
                    !col[currentCol][digit] && 
                    !block[blockRow][blockCol][digit]) {
                    
                   
                    row[currentRow][digit] = true;
                    col[currentCol][digit] = true;
                    block[blockRow][blockCol][digit] = true;
                    board[currentRow][currentCol] = digit + '1';
                    
                   
                    backtrack(cellIndex + 1);
                    
                    
                    if (solved) return;
                    
                    
                    row[currentRow][digit] = false;
                    col[currentCol][digit] = false;
                    block[blockRow][blockCol][digit] = false;
                }
            }
        };
        
        
        backtrack(0);
    }
};
