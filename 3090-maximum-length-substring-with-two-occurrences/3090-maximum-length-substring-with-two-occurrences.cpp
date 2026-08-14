class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int>f(26,0);
        int j=0,ans=0;
        for(int i=0;i<s.size();i++){
            f[s[i]-'a']++;
            while(f[s[i]-'a']>2){
                f[s[j]-'a']--;
                j++;
            }
            ans=max(ans,i-j+1);
        }
        return ans;
    }
};