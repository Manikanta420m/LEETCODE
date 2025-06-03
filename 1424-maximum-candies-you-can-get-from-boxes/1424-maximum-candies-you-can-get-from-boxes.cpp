class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n=status.size();
        long long ans=0;
        queue<int>q;
        vector<bool>vis(n,false);
        for(auto &i:initialBoxes){
            if(status[i]==1)q.push(i);
            else vis[i]=true;
        }
        while(!q.empty()){
            int box=q.front();
            q.pop();
            ans+=candies[box];
            for(int i:containedBoxes[box]){
                if(status[i]==1){
                    q.push(i);
                    status[i]=0;
                }
                else vis[i]=true;
            }
            for(int K:keys[box]){
                if(vis[K] && status[K]==0)q.push(K);
                status[K]=1;
            }
        }return ans;
    }
};