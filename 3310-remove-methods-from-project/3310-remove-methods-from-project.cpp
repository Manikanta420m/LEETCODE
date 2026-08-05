constexpr int MAXN=100005;
class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>>edges(n);
        vector<int>indeg(n,0);
        bitset<MAXN>bit;
        for(auto i:invocations){
            edges[i[0]].push_back(i[1]);
            indeg[i[1]]++;
        }
        queue<int>q;
        q.push(k);
        bit.set(k);
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int v:edges[u]){
                indeg[v]--;
                if(!bit.test(v)){
                    q.push(v);
                    bit.set(v);
                }
            }
        }
        vector<int>ans;
        bool f=true;
        for(int i=0;i<n;i++){
            if(bit.test(i) and indeg[i]>0){
                f=false;
                break;
            }
            else if(!bit.test(i)){
                ans.push_back(i);
            }
        }
        if(!f){
             vector<int>all(n);
             iota(all.begin(),all.end(),0);
             return all;
        }
        return ans;
    }
};