class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
      vector<int>diff(nums.size()+1,0);
      for(auto i:queries){
        diff[i[0]]++;
        diff[i[1]+1]--;
      }  
      for(int i=0;i<nums.size();i++){
        if(i>0) diff[i]+=diff[i-1];
        if(diff[i]<nums[i])return false;
      }
      return true;
    }
};