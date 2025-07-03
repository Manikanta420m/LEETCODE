class Solution {
public:
    char kthCharacter(int k) {
        string ans="a";
        while(ans.length()<k){
            int siz=ans.size();
            for(int i=0;i<siz;i++){
                ans.push_back('a'+(ans[i]-'a'+1)%26);
            }
        }return ans[k-1];
    }
};