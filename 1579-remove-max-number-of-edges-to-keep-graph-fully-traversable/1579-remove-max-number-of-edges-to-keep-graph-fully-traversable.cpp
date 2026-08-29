class DSU{
public:
   vector<int>parent,rank;
   DSU(int n){
    parent.resize(n);
    rank.resize(n);
    for(int i=0;i<n;i++)parent[i]=i;
   }
   int Find(int x){
    return parent[x] = parent[x] == x ? x : Find(parent[x]);
   }
   bool Union(int x,int y){
    int xset=Find(x),yset=Find(y);
    if(xset!=yset){
        rank[xset]<rank[yset] ? parent[xset] = yset : parent[yset] = xset;
        rank[xset]+=rank[xset]==rank[yset];
        return true;
    }
    return false;
   }
};
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        sort(edges.begin(),edges.end(),[&](auto const &a,auto const &b){
           return a[0]>b[0];
        });
        DSU alice(n+1);
        DSU bob(n+1);
        int rem=0,aliceEdges=0,bobEdges=0;
        for(auto e:edges){
            if(e[0]==3){
                if(alice.Union(e[1],e[2])){
                    bob.Union(e[1],e[2]);
                    aliceEdges++;
                    bobEdges++;
                }
                else rem++;
            }
            else if(e[0]==2){
                if(bob.Union(e[1],e[2])){
                    bobEdges++;
                }
                else rem++;
            }
            else{
               if(alice.Union(e[1],e[2])){
                    aliceEdges++;
                }
                else rem++;
            }
        }
        return (bobEdges==n-1 and aliceEdges==n-1)? rem : -1;
    }
};