class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int,int>mp;
        int res=0;
        for(int i=0;i<nums.size();i++){
            int num=nums[i];
            if(mp.count(num) && mp[num]>=3*res){
                res=(mp[num]+1+2)/3;
            }
            mp[num]=i;
        }return res;
    }
};