class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        long long ans=0;
        for(int i=0;i<queries.size();i++){
            int l=queries[i][0];
            int r=queries[i][1];
            long long k=4,prev=l,res=0,mul=1;
            while(k<=r){
              if(k>=prev){
                res+=(k-prev)*mul*1LL;
              }
              prev=max(k,prev);
              mul++;
              k*=4;
            }
            res+=(r-prev+1)*1LL*mul;
            ans+=(res+1LL)/2LL;
        }  
        return ans;
    }
};