class Solution {
public:
    int minOperations(string s) {
        string str=s;
        int n=s.size();
        sort(str.begin(),str.end());
        unordered_map<char,int>mp;
        for(auto i:s)mp[i]++;
        if(s==str)return 0;
        if(n==2)return -1;
        if(s[0]==str[n-1] and s[n-1]==str[0] and mp[s[0]]==1 and mp[s[n-1]]==1)return 3;
        if(s[0]!=str[0] and s[n-1]!=str[n-1])return 2;
        return 1;
    }
};