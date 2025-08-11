class Solution {
public:
    const int M=1e9+7;
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<long>p;
        vector<int>ans;
        int i=0,k=0;
        while(n>0){
            if(n&1){
                p.push_back(i);
                if(k)p[k]+=p[k-1];
                k++;
            }
            n>>=1;
            i++;
        }
        for(auto &q:queries){
            int res=p[q[1]]-(q[0]?p[q[0]-1]:0);
            ans.push_back(fastPow(2,res));
        }
        return ans;
    }

private:
    int fastPow(int base, int exp) {
        int res = 1;
        while (exp) {
            if (exp & 1) res = (1LL * res * base) % M;
            base = (1LL * base * base) % M;
            exp >>= 1;
        }
        return res;
    }
};