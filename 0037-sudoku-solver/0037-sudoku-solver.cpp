class Solution {
private:
    bool isValid(vector<vector<char>>& board,int r,int c,char val){
       for(int i=0;i<9;i++){
          if(board[i][c]==val)return false;
          if(board[r][i]==val)return false;
          if(board[3*(r/3)+(i/3)][3*(c/3)+(i%3)]==val)return false;
       }
       return true;
    }

    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                  if(board[i][j]=='.'){
                      for (char k = '1'; k <= '9'; k++) {
                          if (isValid(board, i, j, k)) {
                              board[i][j] = k;
                              if (solve(board))
                                  return true;
                              else
                                  board[i][j] = '.';
                          }
                      }
                      return false;
                  }
            }
        }
        return true;
    }

public:
    void solveSudoku(vector<vector<char>>& board) { solve(board); }
};