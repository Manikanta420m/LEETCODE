class Solution {
    static constexpr int maxi=31622;
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto i:nums)mp[i]++;
        int ans=(mp[1]-1)|1;
        mp.erase(1);
        for(auto i:mp){
            int cnt=0,ele=i.first;
            int s2=sqrt(ele);
            if(s2*s2==ele and mp.count(s2) and mp[s2]>1)continue;
            while(ele<=maxi and mp.count(ele) and mp[ele]>1){
                cnt+=2;
                ele*=ele;
            }
            ans=fmax(ans,cnt+((mp.count(ele)<<1)-1));
        }
        return ans;
    }
};