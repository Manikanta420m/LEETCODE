class Solution {
public:
    int maxDepth(string s) {
        stack<int>st;
        int pop_streak=0,ans=0,maxi=0;
        for(auto i:s){
           if(i=='('){
            pop_streak++;
           }
           else if(i==')'){
            pop_streak--;
           }
           maxi=max(maxi,pop_streak);
           ans=max(ans,maxi-pop_streak);
        }
        return ans;
    }
};