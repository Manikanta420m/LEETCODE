class Solution {
public:
    int getLeastFrequentDigit(int n) {
        map<int,int>mp;
        while(n>0){
            int x=n%10;
            mp[x]++;
            n/=10;
        }
        int mini=1e9,ans;
        for(auto i:mp){
            if(i.second<mini){
                mini=i.second;
                ans=i.first;
            }
        }
        return ans;
    }
};