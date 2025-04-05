class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
    int xori=0;
     vector<int>ans;
     int n=nums.size();
     int maxi=pow(2,maximumBit)-1;
    for(auto i:nums)xori^=i;
    for(int i=n-1;i>=0;i--){
        ans.push_back(maxi^xori);
        xori^=nums[i];
    }//reverse(ans.begin(),ans.end());
    return ans;
    }
};