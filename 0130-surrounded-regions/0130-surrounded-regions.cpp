class Solution {
    vector<int>dx{1,-1,0,0};
    vector<int>dy{0,0,1,-1};
private:
    void dfs(int r,int c,vector<vector<char>>& board,vector<vector<int>>&vis){
        vis[r][c]=1;
        board[r][c]='Y';
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<4;i++){
            int nr=r+dx[i];
            int nc=c+dy[i];
            if(nr>=0 and nr<n and nc>=0 and nc<m and board[nr][nc]=='O'){
                if(!vis[nr][nc]){
                    dfs(nr,nc,board,vis);
                }
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            if(board[i][0]=='O')dfs(i,0,board,vis);
            if(board[i][m-1]=='O')dfs(i,m-1,board,vis);
        }
        for(int i=0;i<m;i++){
            if(board[0][i]=='O')dfs(0,i,board,vis);
            if(board[n-1][i]=='O')dfs(n-1,i,board,vis);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]!='Y' and board[i][j]=='O')board[i][j]='X';
                else if(board[i][j]=='Y')board[i][j]='O';
            }
        }
    }
};