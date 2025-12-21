class Solution {
public:
    long long maximumScore(vector<int>& nums, string s) {
        long long ans=0;
        priority_queue<int>q;
        for(int i=0;i<nums.size();i++){
            q.push(nums[i]);
            if(s[i]=='1'){
                ans+=q.top();
                q.pop();
            }
        }
        return ans;
    }
};