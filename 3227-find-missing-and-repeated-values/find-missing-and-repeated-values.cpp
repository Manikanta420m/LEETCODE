class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        int ans=n*n;
        long long rsum=1LL*ans*(ans+1)/2;
        long long ssum=1LL*ans*(ans+1)*(2*ans+1)/6; 

        long long asum1=0,asum2=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                asum1+=grid[i][j];
                asum2+=(long long)grid[i][j]*grid[i][j];
            }
        }

        long long dif1=asum1-rsum;
        long long dif2=asum2-ssum;

        long long sumab=dif2/dif1;

        int a=(sumab+dif1)/2;
        int b=(sumab-dif1)/2;
        return {a,b};
    }
};