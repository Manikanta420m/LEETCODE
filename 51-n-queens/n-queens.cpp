class Solution {
public:

   void solve(int col,vector<string>&board, vector<vector<string>>&ans,vector<int>&left,vector<int>&up,vector<int>&down,int n){
    if(col==n){
        ans.push_back(board);
        return;
    }
        for(int row=0;row<n;row++){
            if(left[row]==0 && down[col+row]==0 && up[n-1+col-row]==0){
                board[row][col]='Q';
                left[row]=1;
                down[col+row]=1;
                up[n-1+col-row]=1;
                solve(col+1,board,ans,left,up,down,n);
                board[row][col]='.';
                 left[row]=0;
                down[col+row]=0;
                up[n-1+col-row]=0;
            }
        }
   }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n,'.');
        for(int i=0;i<n;i++)board[i]=s;
        vector<int>left(n,0),up(2*n-1,0),down(2*n-1,0);
        solve(0,board,ans,left,up,down,n);
        return ans;
    }
};