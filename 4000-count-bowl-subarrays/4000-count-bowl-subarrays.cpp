class Solution {
public:
    long long bowlSubarrays(vector<int>& nums) {
        long long ans=0;
        stack<int>st;
        for(int i=0;i<nums.size();i++){
           while(!st.empty() and st.top()<nums[i]){
              st.pop();
              if(!st.empty())ans++;
           }
           st.push(nums[i]);
        }
        return ans;
    }
};