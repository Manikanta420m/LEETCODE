class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>ans(n-k+1,vector<int>(m-k+1));
        for(int i=0;i<=n-k;i++){
            for(int j=0;j<=m-k;j++){
                vector<int>ele;
                for(int r=i;r<i+k;r++){
                    for(int c=j;c<j+k;c++){
                        ele.push_back(grid[r][c]);
                    }
                }
                sort(ele.begin(),ele.end());
                ele.erase(unique(ele.begin(),ele.end()),ele.end());
                if(ele.size()==1)ans[i][j]=0;
                else{
                    int diff=INT_MAX;
                    for(int x=1;x<ele.size();x++){
                        diff=min(diff,ele[x]-ele[x-1]);
                    }ans[i][j]=diff;
                }
            }
        }return ans;
    }
};