class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        int n=spells.size(),m=potions.size();
        vector<int>ans(n,0);
        int maxi=potions[m-1];
        for(int i=0;i<n;i++){
            long long k=(spells[i]+success-1)/spells[i];
            if(k<=maxi){
               ans[i]=m-(lower_bound(potions.begin(),potions.end(),k)-potions.begin());
            }
        }
        return ans;
    }
};