class DSU{
public :
   vector<int>parent,rank;
   DSU(int n){
        parent.resize(n);
        rank.resize(n);
        for(int i=0;i<n;i++)parent[i]=i;
   }
   int find(int x){
        return parent[x] = parent[x] == x ? x : find(parent[x]);
   }
   bool Union(int x,int y){
        int xset=find(x),yset=find(y);
        if(xset!=yset){
        rank[xset]<rank[yset] ? parent[xset]=yset : parent[yset]=xset;
        return true;
        }
    return false;
   }
};
class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n=s.size();
        DSU dsu(n);
        for(auto i:pairs){
            dsu.Union(i[0],i[1]);
        }
        unordered_map<int,vector<int>>components;
        for(int i=0;i<n;i++){
            int root=dsu.find(i);
            components[root].push_back(i);
        }
        for(auto i:components){
            vector<int>idx = i.second;
            vector<char>chars;
            for(auto j:idx){
                chars.push_back(s[j]);
            }
            sort(chars.begin(),chars.end());
            sort(idx.begin(),idx.end());
            for(int j=0;j<idx.size();j++){
                s[idx[j]]=chars[j];
            }
        }
        return s;
    }
};