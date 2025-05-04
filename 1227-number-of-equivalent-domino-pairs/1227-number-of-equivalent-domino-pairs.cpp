class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int mp[100]={0},ans=0;
        for(int i=0;i<dominoes.size();i++){
    int ansi=min(dominoes[i][0],dominoes[i][1])*10+max(dominoes[i][0],dominoes[i][1]);
        ans+=mp[ansi];
        mp[ansi]++;
        }
        return ans;
    }
};