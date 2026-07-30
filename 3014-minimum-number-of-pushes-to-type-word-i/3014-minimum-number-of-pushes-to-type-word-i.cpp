class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size(),ans=0,c=1;
        while(n>0){
            if(n>=8)ans+=(8*c);
            else ans+=(n*c);
            n-=8;
            c++;
        }
        return ans;
    }
};