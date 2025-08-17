class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        long long sm=0,k2=k/2;
        int n=prices.size();
        vector<long long>pre(n+1,0);
        for(int i=0;i<n;i++){
            sm+=(1LL*prices[i]*strategy[i]);
            pre[i+1]=sm;
        }
        
        long long modify=accumulate(prices.begin()+k2,prices.begin()+k,0LL);
        long long profit=max(pre.back(),modify+pre.back()-pre[k]);

        for(int i=1;i<=n-k;i++){
            modify+=prices[i+k-1]-prices[i+k2-1];
            profit=max(profit,modify+pre.back()-pre[i+k]+pre[i]);
        }
        return profit;
    }
};