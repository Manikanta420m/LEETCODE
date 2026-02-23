class Solution {
public:

    map<pair<int,pair<int,pair<int,int>>>,long long>mp;
    int solve(int i, int a, int b, int c, long long k, vector<int>&nums)
    {
        if(i==nums.size())
        {
            if(a>=0 && b>=0 && c>=0)
            {
                long long val= pow(2,a) * pow(3,b) * pow(5,c);
                return (k==val);
            }
            return 0;
        }

        if(mp.find({i,{a,{b,c}}})!=mp.end())
        {
            return mp[{i,{a,{b,c}}}];
        }

        int aa=0;
        int bb=0;
        int cc=0;
        if(nums[i]==2 || nums[i]==4)
        {
            aa+=nums[i]/2;
        }
        else if(nums[i]==3)
        {
            bb++;
        }
        else if(nums[i]==5){
            cc++;
        }
        else if(nums[i]==6)
        {
            aa++;
            bb++;
        }
        int ans=solve(i+1,a,b,c,k,nums);
        ans+=solve(i+1,a+aa,b+bb,c+cc,k,nums);
        ans+=solve(i+1,a-aa,b-bb,c-cc,k,nums);
        return mp[{i,{a,{b,c}}}]=ans;
    }
    int countSequences(vector<int>& nums, long long k) {
        return solve(0,0,0,0,k,nums);
    }
};