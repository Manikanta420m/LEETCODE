class Solution {
public:
    const int M=1e9+7;
    int numSub(string s) {
        int ans=0,c=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0')c=0;
            else c++;
            ans=(ans+c)%M;
        }
        return ans;
    }
};