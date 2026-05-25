class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n=s.size();

        if(s.back()&1)return false;

        s[0]='v';
        int ans=0,maxi=maxJump;
        for(int i=minJump;i<n;i++){
            if(maxi<i)return false;
            ans+=s[i-minJump]=='v';
            ans-=(i>maxJump) and s[i-maxJump-1]=='v';
            if(ans and s[i]=='0'){
                s[i]='v';
                maxi=i+maxJump;
            }
        }
        return ans;
    }
};