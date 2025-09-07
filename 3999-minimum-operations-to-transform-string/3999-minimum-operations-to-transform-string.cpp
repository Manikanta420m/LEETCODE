class Solution {
public:
    int minOperations(string s) {
        vector<int>v(26,0);
        for(int i=0;i<s.size();i++)v[s[i]-'a']++;
        int ans=0;
        for(int i=1;i<26;i++){
            if(v[i]>=1){
               return 26-i;
            }
        }
        return 0;
    }
};