class Solution {
public:
    void f(const vector<int>& nums,int i,int cur,int maxi,int & cnt){
        if(cur==maxi)cnt++;
        for(int j=i;j<nums.size();j++){
            f(nums,j+1,cur|nums[j],maxi,cnt);
        }
    } 
    int countMaxOrSubsets(vector<int>& nums) {
        int maxi=0;
        for(auto i:nums)maxi|=i;
        int cnt=0;
        f(nums,0,0,maxi,cnt);
        return cnt;
    }
};