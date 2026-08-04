class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mini=INT_MAX,maxi=INT_MIN;
        bitset<101>bit;
        for(auto i:nums){
            maxi=max(maxi,i);
            mini=min(mini,i);
            bit.set(i);
        }
        vector<int>ans;
        for(int i=mini;i<=maxi;i++){
            if(!bit.test(i))
               ans.push_back(i);
        }
        return ans;
    }
};