class Solution {
public:
    double champagneTower(int poured, int r, int c) {
        double dp[102][102]={0,0};
        dp[0][0]=(double)poured;

        for(int i=0;i<=r;i++){
            for(int j=0;j<=i;j++){
               if(dp[i][j]>1.0){
                double ext=(dp[i][j]-1.0)/2.0;
                dp[i][j]=1.0;
                dp[i+1][j]+=ext;
                dp[i+1][j+1]+=ext;
               }
            }
        }
        return dp[r][c];
    }
};