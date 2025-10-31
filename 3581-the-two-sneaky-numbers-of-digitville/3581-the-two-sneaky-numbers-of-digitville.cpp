class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int hash[101];
         vector<int>ans;
        for(int i=0;i<=100;i++)hash[i]=0;
        for(int i=0;i<nums.size();i++){
            hash[nums[i]]++;
        }
        for(int i=0;i<=100;i++){
            if(hash[i]==2){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
