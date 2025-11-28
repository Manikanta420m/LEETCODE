class Solution {
    int f(vector<vector<int>>&a,vector<int>& values,int & k,int & c,int cur,int p=-1){
        long long sum=values[cur];
        for(int i:a[cur]){
            if(i!=p)
                sum+= f(a,values,k,c,i,cur);
            }
            sum%=k;
            if(sum==0)c++;
            return sum;
        
    }
    public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>>a(n);
        for(auto i:edges){
            a[i[0]].push_back(i[1]);
            a[i[1]].push_back(i[0]);
        }
        int c=0;
        f(a,values,k,c,0);
        return c;
    }
};