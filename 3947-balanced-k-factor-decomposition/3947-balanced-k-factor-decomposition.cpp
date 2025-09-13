class Solution {
public:
    vector<int>best;
    int best_diff=INT_MAX;
    vector<int> minDifference(int n, int k) {
        vector<int>cur;
        solve(n,k,1,cur);
        return best;
    }

    void solve(int n,int k,int start,vector<int>&cur){
        if(k==1){
            if(n>=start){
              cur.push_back(n);
              check(cur);
              cur.pop_back();
            }
            return;
        }
        for(int i=start;i<=n;i++){
            if(n%i==0){
                cur.push_back(i);
                solve(n/i,k-1,i,cur);
                cur.pop_back();
            }
        }
    }

    void check(vector<int>& cur) {
        int mn = *min_element(cur.begin(), cur.end());
        int mx = *max_element(cur.begin(), cur.end());
        if (mx - mn < best_diff) {
            best_diff = mx - mn;
            best = cur;
        }
    }
};