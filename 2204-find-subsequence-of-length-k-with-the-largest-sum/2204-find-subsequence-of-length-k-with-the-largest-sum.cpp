class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
      vector<int>ans;
      priority_queue<pair<int,int>>q;
      for(int i=0;i<nums.size();i++){
        q.push({nums[i],i});
      }
      for(int i=0;i<k;i++){
        ans.push_back(q.top().second);
        q.pop();
      }
      sort(ans.begin(),ans.end());
      for(int i=0;i<ans.size();i++){
        ans[i]=nums[ans[i]];
      }
      return ans;
    }
};