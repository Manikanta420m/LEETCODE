class Solution {
public:
    void solve(string cur,string &tiles,unordered_set<string>&ans, vector<bool>&f){
        ans.insert(cur);
        for(int i=0;i<tiles.size();i++){
            if(!f[i]){
                f[i]=true;
                solve(cur+tiles[i],tiles,ans,f);
                f[i]=false;
            }
        }
    }
    int numTilePossibilities(string tiles) {
      unordered_set<string>ans;
      vector<bool>f(tiles.size(),false);
      solve("",tiles,ans,f);
      return ans.size()-1;  
    }
};