class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
       int ans=0,sum=0;
       int l=0,r=0,prev=0;
       unordered_set<int>st;
       while(r<nums.size()){
         while(st.count(nums[r])){
            st.erase(nums[l]);
            sum-=nums[l];
            l++;
         }
         st.insert(nums[r]);
         sum+=nums[r];
         ans=max(ans,sum);
         prev=st.size();
         r++;
       }
       return ans;
    }
};