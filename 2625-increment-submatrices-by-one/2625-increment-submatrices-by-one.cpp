class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
      vector<vector<int>>ans(n,vector<int>(n,0));
      for(auto i:queries){
        int r1=i[0],c1=i[1],r2=i[2],c2=i[3];
        ans[r1][c1]+=1;
       if(r2+1<n) ans[r2+1][c1]-=1;
       if(c2+1<n) ans[r1][c2+1]-=1;
       if(r2+1<n and c2+1<n) ans[r2+1][c2+1]+=1;
      }
      for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int left=0,up=0,dia=0;
            if(j>0)left=ans[i][j-1];
            if(i>0)up=ans[i-1][j];
            if(i>0 and j>0)dia=ans[i-1][j-1];
           ans[i][j]+=left+up-dia;
        }
      }
      return ans;
    }
};