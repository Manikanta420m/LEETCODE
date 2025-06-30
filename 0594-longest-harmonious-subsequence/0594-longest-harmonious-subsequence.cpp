class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int,int>mp;
        for(int i=0;i<nums.size();i++)mp[nums[i]]++;
        int maxi=0,prev=1e9+1,pre_no=0;
        bool f=true;
        for(auto i:mp){
          if(f){
            prev=i.first;
            pre_no=i.second;
            f=false;
            continue;
          }
          else if(i.first-1==prev)maxi=max(maxi,pre_no+i.second);
           prev=i.first;
           pre_no=i.second;
        }
        return maxi;
    }
};