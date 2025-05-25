class Solution {
public:
    int maxSubstrings(string word) {
        int ans=0,n=word.size(),wait=0;
        unordered_set<char>st;
        if(n<4)return 0;
        for(int i=3;i<n;i++){
            if(wait==0)st.insert(word[i-3]);
            if(wait>0)wait--;
            if(st.find(word[i])!=st.end()){ans++;st.clear();wait=3;}
        }return ans;
    }
};