class Solution {
public:
    int countCommas(int n) {
        int lmt=1000;
        int ans=0;
        while(n>=lmt){
          ans+=(n-lmt+1);
            lmt*=1000;
        }
        return ans;
    }
};