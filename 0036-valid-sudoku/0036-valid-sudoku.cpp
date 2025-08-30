class Solution {
public:
bool check(vector<vector<char>>& board,int res,int i,int j){
         for(int a=0;a<9;a++){
            if(a!=j&&board[i][a]==res){
                return false;
            }
         }
          for(int a=0;a<9;a++){
            if(a!=i&&board[a][j]==res){
                return false;
            }
         }
         int r=i-(i%3);
         int c=j-(j%3);
         for(int a=0;a<3;a++){
            for(int b=0;b<3;b++){
                if((board[a+r][b+c]==res)&&((a+r)!=i&&(b+c)!=j)){
                    return false;
                }
            }
         }
         return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        int i,j;
        for(i=0;i<9;i++){
            for(j=0;j<9;j++){
               if(board[i][j]!='.'){
                int res=board[i][j];
                if(!check(board,res,i,j))
                return false;
               }
            }
        }
        return true;
    }
};
