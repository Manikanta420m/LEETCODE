class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int>mp;
        int ans=0;
        for(int i=0;i<words.size();i++){
            string rev=words[i];
            reverse(rev.begin(),rev.end());
            if(mp[rev]>0){
                ans+=4;
                mp[rev]--;
            }
            else mp[words[i]]++;
        }
        for(auto i:mp){
            string s=i.first;
            if(s[0]==s[1] and i.second>0){ans+=2;break;}
        }
        return ans;
    }
};