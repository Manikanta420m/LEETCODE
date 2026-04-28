class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
       int n=grid.size(),m=grid[0].size();
       int mini=INT_MAX,maxi=INT_MIN,g=grid[0][0];
       vector<int>a;
       for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
             a.push_back(grid[i][j]);
          }
       }
       int reso=a[0]%x;
       for(auto i:a)if(i%x!=reso)return -1;
       sort(a.begin(),a.end());
       int ans=0,req=a[a.size()/2];
       for(auto i:a)ans+=abs(req-i)/x;
       return ans;
    }
};