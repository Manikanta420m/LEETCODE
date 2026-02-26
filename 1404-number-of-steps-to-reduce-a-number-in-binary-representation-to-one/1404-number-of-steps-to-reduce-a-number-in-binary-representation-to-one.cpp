class Solution {
public:
    int numSteps(string s) {
         int n=s.size(),ans=0,c=0;
        for(int i=n-1;i>0;i--){
            if((s[i]&1)+c==1){
               ans++;
               c=1;
            }
            ans++;
        }
        return ans+c;
    }
};