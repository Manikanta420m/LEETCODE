class Solution {
public:
    long long minCuttingCost(int n, int m, int k) {
        long long ans=0;
        if(n>k)ans+=(long long)(n-k)*k;
        if(m>k)ans+=(long long)(m-k)*k;
        return (long long)ans;
    }
};