class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int,int>mp;
        int ans=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i])!=mp.end()){
                ans=min(ans,i-mp[nums[i]]);
            }
            string s=to_string(nums[i]);
            reverse(s.begin(),s.end());
            int num=(int)stoi(s);
           // if (mp.find(num) == mp.end())
                mp[num] = i;
        }
        return ans==INT_MAX?-1:ans;
    }
};