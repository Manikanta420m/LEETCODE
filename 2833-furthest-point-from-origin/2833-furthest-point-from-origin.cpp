class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int ans=0;
        int c1=0,c2=0;
        for(auto i:moves){
            if(i=='R')c1++;
            else c1--;
            if(i=='L')c2++;
            else c2--;
            ans=max(abs(c1),abs(c2));
        }
        return ans;
    }
};