class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
       int xr=0;
       for(auto i:nums)xr^=i;
       int bit=1;
       while((xr&bit)==0)bit<<=1;
       int x=0,y=0;
       for(auto i:nums){
        if(i&bit){
            x^=i;
        }
        else y^=i;
       }
       return {x,y};
    }
};