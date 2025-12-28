class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans=0;
        int n=grid.size();
        int m=grid[0].size();
        int j=m-1;
        for(int i=0;i<n;i++){
            while(j>=0 and grid[i][j]<0)j--;
            if(j<0)break;
            ans+=(j+1);
        }
        return (n*m)-ans;
    }
};