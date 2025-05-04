class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int,int>mp;
        int ans=0;
        for(int i=0;i<dominoes.size();i++){
    int ans=min(dominoes[i][0],dominoes[i][1])*10+max(dominoes[i][0],dominoes[i][1]);
        mp[ans]++;
        }
        for(auto i:mp){
          int n=i.second-1;
          ans+=n*(n+1)/2;
        }return ans;
    }
};