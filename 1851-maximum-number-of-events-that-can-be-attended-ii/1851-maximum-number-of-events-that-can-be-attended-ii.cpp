class Solution {
    vector<vector<int>>mem;
    vector<int>next;
    int n;

    int solve(vector<vector<int>>& events,int pos, int k) {
        if(k==0 or pos>=n)return 0;
        if(mem[pos][k]!=-1)return mem[pos][k];

        int skip=solve(events,pos+1,k);

        int nxt=next[pos];
        int attend=solve(events,nxt,k-1)+events[pos][2];
        return mem[pos][k]=max(attend,skip);
    }

public:
    int maxValue(vector<vector<int>>& events, int k) {
        n=events.size();
        mem.assign(n,vector<int>(k+1,-1));
        sort(events.begin(),events.end());
        next=vector<int>(n);
        for(int i=0;i<n;i++){
        next[i]=upper_bound(events.begin()+i,events.end(),vector<int>{events[i][1]+1,0,0})-events.begin();
        }
        return solve(events,0,k);
    }
};