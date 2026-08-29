class Solution {
public:
    bool is_similar(string s1,string s2){
        int cnt=0;
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i])cnt++;
        }
        return (cnt==2 or cnt==0);
    }
    void dfs(int i,vector<string>& strs,vector<bool>&vis){
       vis[i]=true;
       for(int j=0;j<strs.size();j++){
        if(vis[j])continue;
        if(is_similar(strs[i],strs[j])){
            dfs(j,strs,vis);
        }
       }
    }
    int numSimilarGroups(vector<string>& strs) {
        int cnt=0,n=strs.size();
        vector<bool>vis(n,false);
        for(int i=0;i<n;i++){
            if(vis[i])continue;
            cnt++;
            dfs(i,strs,vis);
        }
        return cnt;
    }
};