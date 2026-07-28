class Solution {
public:
    string smallestPalindrome(string s) {
        string s1,s2;
        sort(s.begin(),s.end());
        char las;
        int n=s.size();
        for(int i=0;i<s.size();i++){
            if(s[i]!=s[i+1] && i<s.size()-1 || i==n-1){las=s[i];continue;}
            s1.push_back(s[i]);i++;
            s2.push_back(s[i]);
        }
        if(s.size()&1)s1.push_back(las);
        reverse(s2.begin(),s2.end());
        return s1+s2;
    }
};