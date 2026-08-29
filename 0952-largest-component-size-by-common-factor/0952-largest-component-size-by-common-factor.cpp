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
  bool Union(int x,int y){
    int xset=find(x) , yset = find(y);
    if(xset!=yset){
      rank[xset]<rank[yset] ? parent[xset]=yset : parent[yset]=xset;
      rank[xset]+=rank[xset]==rank[yset];
      return true;
    }
    return false;
  }
};

class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
        int n=nums.size();
        DSU dsu(n);
        unordered_map<int,int>facIdx;
        for(int i=0;i<n;i++){
            int x=nums[i];
            for(int d=2;d*d<=x;d++){
                if(x%d==0){
                    if(facIdx.count(d)){
                        dsu.Union(i,facIdx[d]);
                    }
                    else{
                        facIdx[d]=i;
                    }
                    while(x%d==0)x/=d;
                }
            }
            if(x>1){
                if(facIdx.count(x)){
                        dsu.Union(i,facIdx[x]);
                    }
                else{
                        facIdx[x]=i;
                    }
            }
        }
        unordered_map<int,int>cnt;
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,++cnt[dsu.find(i)]);
        }
        return ans;
    }
};