class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        int maxi=n*n;
        queue<int>q;
        q.push(1);
        vector<bool>vis(maxi+1,false);
        vis[1]=true;
        int lvl=0;
        while(!q.empty()){
            int siz=q.size();
            for(int i=0;i<siz;i++){
                int cur=q.front();
                q.pop();
                if(cur==maxi)return lvl;
                for(int nxt=cur+1;nxt<=min(cur+6,maxi);nxt++){
                    int dest=nxt;
                    int row=(nxt-1)/n;
                    int col=(nxt-1)%n;
                    if(row%2==1){
                        col=n-1-col;
                    }
                    row=n-1-row;
                    if(board[row][col]!=-1)
                       dest=board[row][col];
                    if(!vis[dest]){
                        vis[dest]=true;
                        q.push(dest);
                    }
                }
            }lvl++;
        }return -1;
    }
};