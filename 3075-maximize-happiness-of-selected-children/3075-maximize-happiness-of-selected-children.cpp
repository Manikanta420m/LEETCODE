class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long ans=0,x=0;
        sort(happiness.rbegin(),happiness.rend());
        for(int i=0;i<k;i++){
            ans+=max(happiness[i]-x,0LL);
            x++;
        }
        return ans;
    }
};