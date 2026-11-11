class Solution {
public:
    long long minimumCost(int c1, int c2, int cb, int n1, int n2) {
        long long ans=0;
        ans=(long long)((long long)(1LL*c1*n1*1LL)+(long long)(1LL*c2*n2*1LL));
        ans=min(ans,(long long)max(n1,n2)*cb*1LL);
        if(n1<n2)ans=min(ans,(long long)cb*1LL*min(n1,n2)*1LL+abs(n1-n2)*1LL*c2*1LL);
        else ans=min(ans,(long long)cb*1LL*min(n1,n2)*1LL+abs(n1-n2)*1LL*c1*1LL);
        return ans;
    }
};