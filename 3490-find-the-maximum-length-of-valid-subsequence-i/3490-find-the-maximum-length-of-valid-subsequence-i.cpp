class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int eve=0,odd=0;
        for(auto i:nums){
            if(i&1)odd++;
            else eve++;
        }
        int ans=max(eve,odd);
        int f=0,c=0;
        for(auto i:nums){
            if(i%2==f){c++;f^=1;}
        }
        ans=max(c,ans);
        c=0,f=1;
        for(auto i:nums){
            if(i%2==f){c++;f^=1;}
        }
        ans=max(ans,c);
        return ans;
    }
};