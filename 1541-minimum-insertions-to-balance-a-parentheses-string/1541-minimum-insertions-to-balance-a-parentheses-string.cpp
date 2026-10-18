class Solution {
public:
    int minInsertions(string s) {
        int close=0,ans=0;
        for(auto i:s){
            if(i=='('){
               if(close&1){
                 ans++;
                 close--;
               }
               close+=2;
            }
            else{
               close--;
               if(close<0){
                ans+=1;
                close=1;
               }
            }
        }
        return close+ans;
    }
};