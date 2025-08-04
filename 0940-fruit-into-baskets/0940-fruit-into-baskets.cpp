class Solution {
public:
    int totalFruit(vector<int>& fruits) {
      int ans=0,l=0,r=0;
      int n=fruits.size();
      unordered_map<int,int>mp;
      while(r<n){
       mp[fruits[r]]++;
       while(mp.size()>2 and l<r){
        mp[fruits[l]]--;
        if(mp[fruits[l]]==0)mp.erase(fruits[l]);
        l++;
       }
       ans=max(ans,r-l+1);
       r++;
      }
      return ans;
    }
};