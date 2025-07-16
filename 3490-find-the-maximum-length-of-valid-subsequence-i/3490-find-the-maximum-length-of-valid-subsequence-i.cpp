class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int eve=0,odd=0,ans=0,f=nums[0]%2;
        for(auto i:nums){
            if(i&1)odd++;
            else eve++;
            if(i%2==f){ans++;f^=1;}
        }
        return max(ans,max(eve,odd));
    }
};