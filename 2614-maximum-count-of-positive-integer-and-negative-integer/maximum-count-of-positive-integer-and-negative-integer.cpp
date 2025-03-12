class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int neg=solve(nums,0);
        int pos=nums.size()-solve(nums,1);
        return max(neg,pos);
    }
private:
    int solve(vector<int>& nums,int tar){
        int l=0,r=nums.size()-1,ans=nums.size()-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]<tar)l=mid+1;
            else r=mid-1;
        }return l;
    }
};