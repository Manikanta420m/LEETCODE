class Solution {
public:
    long long minMoves(vector<int>& balance) {
        long long ans=0;
        int n=balance.size();
        if(accumulate(balance.begin(),balance.end(),0LL)<0)return -1;
        int idx=-1;
        for(int i=0;i<n;i++){
            if(balance[i]<0){
                idx=i;
                break;
            }
        }
        if(idx==-1)return 0;
        vector<pair<int,int>>pr;
        for(int i=0;i<n;i++){
            if(i==idx)continue;
            pr.push_back({min(abs(i-idx),min(abs(n-idx+i),abs(n-i+idx))),balance[i]});
        }
        sort(pr.begin(),pr.end());
        int req=abs(balance[idx]);
        for(int i=0;i<pr.size();i++){
           if(pr[i].second>=req){
            ans=ans+(1LL*pr[i].first*req);
            break;
           }
           else {
            ans=ans+(1LL*pr[i].first*pr[i].second);
            req-=pr[i].second;
           }
        }
        return ans;
    }
};