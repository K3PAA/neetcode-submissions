class Solution {
public:
    bool validSquare(vector<vector<char>>& board, int x, int y) {
        vector<bool> values(9, false);
        char ch;
        int num;
        bool g = true;
        for(int i = 0; i < 3; ++i) {
            for(int j = 0; j < 3; ++j) {
                ch = board[3 * x + i][3 * y + j];
                if(ch != '.') {
                    num = ch - '0' - 1;
                    if(values[num]) g = false;
                    values[num] = true;
                }
            }
        }

        return g;
    }
    bool validRow(vector<vector<char>>& board, int y) {
        vector<bool> values(9, false);
        char ch;
        int num;
        bool g = true;
        for(int x = 0; x < 9; ++x) {
            ch = board[y][x];
            if(ch != '.') {
                num = ch - '0' - 1;
                if(values[num]) g = false;
                values[num] = true;
            }
        }

        return g;
    }
    bool validColumn(vector<vector<char>>& board, int x) {
        vector<bool> values(9, false);
        char ch;
        int num;
        bool g = true;
        for(int y = 0; y < 9; ++y) {
            ch = board[y][x];
            if(ch != '.') {
                num = ch - '0' - 1;
                if(values[num]) g = false;
                values[num] = true;
            }
        }

        return g;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        bool valid = true;
        for(int x = 0; x < 3; ++x) {
            for(int y = 0; y < 3; ++y) {
                if(valid) {
                    valid = validSquare(board, x, y);
                }
            }
        }
        if(!valid) return valid;
        for(int x = 0; x < 9; ++x) {
            if(valid) {
                valid = validColumn(board, x);
            }
        }
        if(!valid) return valid;
        for(int y = 0; y < 9; ++y) {
            if(valid) {
                valid = validRow(board, y);
            }
        }
        
        return valid;
    }
};
