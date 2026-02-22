class Solution {
public:
    int binaryGap(int n) {
        if((n&(n-1))==0)return 0;
        int ans=0,c=0;
        bool f=false;
        while(n){
            if(n&1){c=1;f=true;}
            else if(f) c++;
            ans=max(ans,c);
            n=n>>1;
        }
        return ans;
    }
};