class Solution {
public:
    long long ans=0;

    long long squareFree(int num){
        long long pro=1;
        for(int i=2;i*i<=num;i++){
            if(num%i==0){
                long long cnt=0;
                while(num%i==0){
                    cnt++;
                    num/=i;
                }
                if(cnt&1)pro*=i;
            }
        }
        if(num>1)pro*=num;
        return pro;
    }

    void dfs(int node,int par,vector<vector<int>>&adj,unordered_map<long long ,long long>&mp,vector<int>& nums){
       long long form = squareFree(nums[node]);
       if(node!=0){
        ans+=mp[form];
       }
       mp[form]++;
       for(auto child:adj[node]){
        if(child!=par)dfs(child,node,adj,mp,nums);
       }
       mp[form]--;
    }
    long long sumOfAncestors(int n, vector<vector<int>>& edges, vector<int>& nums) {
        vector<vector<int>>adj(n);
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        unordered_map<long long ,long long>mp;
        dfs(0,-1,adj,mp,nums);
        return ans;
    }
};