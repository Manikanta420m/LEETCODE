class Solution {
public:
    string removeOccurrences(string s, string part) {
        string ans=s;
        int n=s.length(),i=0,m=part.length(),k=0;
       for(int i=0;i<n;i++){
            ans[k++]=s[i];
            if(k>=m && ans.substr(k-m,m)==part)k-=m;
        }
        return ans.substr(0,k);
    }
};