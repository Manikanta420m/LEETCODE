class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>ans;
        for(auto i:nums){
            string s=to_string(i);
            for(auto ch:s)ans.push_back(ch-'0');
        }
        return ans;
    }
};