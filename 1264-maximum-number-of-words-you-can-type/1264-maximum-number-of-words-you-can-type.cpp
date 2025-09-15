class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int ans=0;
        bool f=true;
        unordered_set<char>st(brokenLetters.begin(),brokenLetters.end());
        for(int i=0;i<text.size();i++){
            if(text[i]==' '){
                if(f)ans++;
                f=true;
            }
            else if(st.contains(text[i])){
                f=false;
            }
        }if(f)ans++;
        return ans;
    }
};