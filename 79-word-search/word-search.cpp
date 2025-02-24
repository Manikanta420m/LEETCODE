class Solution {
public:

    bool solve(int idx,int jdx,string &s,vector<vector<char>>& board, string word,int cnt){
        if(cnt==word.size())return true;
        if(idx<0 || idx>=board.size() || jdx<0 || jdx>=board[0].size())return false;
        if(board[idx][jdx]!=word[cnt])return false;
        char ch=board[idx][jdx];
        board[idx][jdx]='#';
        bool f1=solve(idx+1,jdx,s,board,word,cnt+1);
        bool f2=solve(idx,jdx+1,s,board,word,cnt+1);
        bool f3=solve(idx-1,jdx,s,board,word,cnt+1);
        bool f4=solve(idx,jdx-1,s,board,word,cnt+1);
        board[idx][jdx]=ch;
        return f1||f2||f3||f4;
    }

    bool exist(vector<vector<char>>& board, string word) {
        string s;
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                   string s="";
                    if(solve(i,j,s,board,word,0))return true;
                }
            }
        }
        return false;
    }
};