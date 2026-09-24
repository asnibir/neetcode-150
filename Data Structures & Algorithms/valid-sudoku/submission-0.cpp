class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int checkRow[9][10] = {false};
        int checkCol[9][10] = {false};
        int checkBox[9][10] = {false};
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {

                if(board[i][j] == '.') continue;

                int val = board[i][j] - '0';
                int boxNumber = (i / 3) * 3 + (j / 3);

                if(checkRow[i][val] || checkCol[j][val] || checkBox[boxNumber][val]) {
                    return false;
                }
                checkRow[i][val] = true;
                checkCol[j][val] = true;
                checkBox[boxNumber][val] = true;

            }   
        }

        return true;
    }
};