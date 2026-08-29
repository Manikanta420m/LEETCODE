class DSU{
  public:
  vector<int>parent,rank;
  DSU(int n){
    parent.resize(n);
    rank.resize(n);
    for(int i=0;i<n;i++)parent[i]=i;
  }
  int find(int x){
    return parent[x] = parent[x] == x ? x : find(parent[x]);
  }
  bool Unite(int x,int y){
    int xset=find(x),yset=find(y);
    if(xset!=yset){
      rank[xset]<rank[yset]?parent[xset]=yset:parent[yset]=xset;
      rank[xset]+=rank[xset]==rank[yset];
      return true;
    }
    return false;
  }
};
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        int n=equations.size();
        DSU dsu(26);
        for(auto i:equations){
            if(i[1]=='='){
                int n1 = i[0]-'a';
                int n2 = i[3]-'a';
                dsu.Unite(n1,n2);
            }
        }
        for(auto i:equations){
            if(i[1]=='!'){
                int n1 = i[0]-'a';
                int n2 = i[3]-'a';
                int x = dsu.find(n1);
                int y = dsu.find(n2);
                if(x==y)return false;
            }
        }
        return true;
    }
};