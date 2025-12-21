class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans=0;
        unordered_map<int,int>mp;
        for(int i=nums.size()-1;i>=0;i--){
            if(mp.find(nums[i])!=mp.end()){
               return min((int)nums.size(),(int)(i+3)/3);
            }
            else mp[nums[i]]=1;
        }
        return 0;
    }
};