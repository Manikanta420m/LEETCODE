class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int ans=0;
        char ch1='a',ch2='b';
        int cnt1=0,cnt2=0;
        if(x<y){
            swap(x,y);
            ch1='b';
            ch2='a';
        }
        for(auto ch:s){
            if(ch==ch1)cnt1++;
            else if(ch==ch2){
                if(cnt1>0){
                    cnt1--;
                    ans+=x;
                }
                else cnt2++;
            }
            else{
                ans+=min(cnt1,cnt2)*y;
                cnt1=0;
                cnt2=0;
            }
        }
        ans+=min(cnt1,cnt2)*y;
        return ans;
    }
};