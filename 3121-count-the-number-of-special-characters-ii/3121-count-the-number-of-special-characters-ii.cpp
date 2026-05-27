class Solution {
public:
    int numberOfSpecialChars(string word) {
        int ans=0;
        vector<int>small(26,-1),large(26,-1);
        for(int i=0;i<word.size();i++){
            if(word[i]>='a' and word[i]<='z')small[word[i]-'a']=i;
            else if(large[word[i]-'A']==-1)large[word[i]-'A']=i;
        }
        for(int i=0;i<26;i++){
            if(small[i]!=-1 and large[i]!=-1 and large[i]>small[i])ans++;
        }
        return ans;
    }
};