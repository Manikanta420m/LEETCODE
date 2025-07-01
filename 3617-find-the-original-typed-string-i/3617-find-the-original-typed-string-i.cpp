class Solution {
public:
    int possibleStringCount(string word) {
        int ans=1,c=0;
        for(int i=1;i<word.size();i++){
            if(word[i]==word[i-1])c++;
            else {ans+=c;c=0;}
        }ans+=c;
        return ans;
    }
};