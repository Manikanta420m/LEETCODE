class Solution {
public:
    long long countCommas(long long n) {
        long long lmt=1000;
        long long ans=0;
        while(n>=lmt){
          ans+=(n-lmt+1LL);
            lmt*=1000LL;
        }
        return ans;
    }
};