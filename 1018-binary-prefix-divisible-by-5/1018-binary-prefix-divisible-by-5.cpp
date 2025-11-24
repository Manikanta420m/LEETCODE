class Solution {
public:
    const long long M=5;
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        long long num=0;
        vector<bool>ans;
        for(auto i:nums){
            num=(num*2LL)%M;
            if(i==1)num+=1;
            if(num%5==0)ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};