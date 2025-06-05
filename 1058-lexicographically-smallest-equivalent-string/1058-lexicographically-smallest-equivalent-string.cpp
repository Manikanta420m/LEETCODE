class Solution {
public:
    vector<int>parent;

     int find(int x){
        if(parent[x]!=x)
           parent[x]=find(parent[x]);
        return parent[x];
     }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        parent.resize(26);
        for(int i=0;i<26;i++)
             parent[i]=i;
        
        for(int i=0;i<s1.size();i++){
            int u=s1[i]-'a';
            int v=s2[i]-'a';
            int pu=find(u);
            int pv=find(v);
            if(pu<pv)
               parent[pv]=pu;
            else parent[pu]=pv;
        }
        string ans;
        for(auto ch:baseStr){
            char mp=(char)(find(ch-'a')+'a');
            ans.push_back(mp);
        }
        return ans;
    }
};