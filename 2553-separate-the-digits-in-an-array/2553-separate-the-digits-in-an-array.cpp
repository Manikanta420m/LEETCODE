class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>ans;
        for(auto i:nums){
            vector<int>temp;
            int num=i;
            while(num>0){
                temp.push_back(num%10);
                num/=10;
            }
            while(temp.size()){
                ans.push_back(temp.back());
                temp.pop_back();
            }
        }
        return ans;
    }
};