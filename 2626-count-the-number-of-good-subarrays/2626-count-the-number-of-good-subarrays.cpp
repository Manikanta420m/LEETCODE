class Solution {
public:
     //\U0001f92b\U0001f923
    long long countGood(vector<int>& nums, int k) {
        long long ans=0;
        int n=nums.size();
        long long c=0;
        int l=0;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            int val=nums[i];
            c+=mp[val];
            mp[val]++;
            while(c>=k){
                ans+=n-i;
                int out=nums[l++];
                mp[out]--;
                c-=mp[out];
            }
        }return ans;   //I❤️U
    }
};