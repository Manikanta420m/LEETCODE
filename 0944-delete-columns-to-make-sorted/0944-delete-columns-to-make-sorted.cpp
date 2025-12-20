class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int ans=0;
        for(int j=0;j<strs[0].size();j++){
            char ch='a';
            for(int i=0;i<strs.size();i++){
               if(strs[i][j]>=ch){
                ch=strs[i][j];
               }
               else{
                ans++;
                break;
               }
            }
        }
        return ans;
    }
};