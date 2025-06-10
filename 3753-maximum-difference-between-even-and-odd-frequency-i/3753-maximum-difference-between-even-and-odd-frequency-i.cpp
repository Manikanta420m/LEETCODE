class Solution {
public:
    int maxDifference(string s) {
        vector<int>a(26,0);
        int mini=INT_MAX,maxi=INT_MIN;
        for(int i=0;i<s.size();i++){
            a[s[i]-'a']++;
        }
        for(auto &i:a){
            if(i&1)maxi=max(maxi,i);
            else if(i>=2)mini=min(mini,i);
        }
        return maxi-mini;
    }
};