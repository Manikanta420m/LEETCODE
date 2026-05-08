#define ll long long
class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n=nums.size();
        int mx=*max_element(nums.begin(),nums.end());
        vector<bool>prime(mx+1,true);
        prime[0]=prime[1]=false;
        for(ll i=2;i<=mx;i++){
            if(prime[i]){
                for(ll j=i*i;j<=mx;j+=i){
                    prime[j]=false;
                }
            }
        }
        vector<vector<ll>>pos(mx+1);
        for(ll i=0;i<n;i++){
            pos[nums[i]].push_back(i);
        }
        queue<pair<int,int>>q;
        q.push({0,0});
        vector<int>vis(n,0);
        vis[0]=1;
        while(!q.empty()){
            auto it=q.front();
            int i=it.first;
            int t=it.second;
            q.pop();
            if(i==n-1)return t;
            if(i>0 and !vis[i-1]){
                q.push({i-1,t+1});
                vis[i-1]=1;
            }
            if(i<n-1 and !vis[i+1]){
                q.push({i+1,t+1});
                vis[i+1]=1;
            }
            if(prime[nums[i]]){
                int p=nums[i];
                for(int m=p;m<=mx;m+=p){
                    for(auto j:pos[m]){
                        if(!vis[j]){
                            q.push({j,t+1});
                            vis[j]=1;
                        }
                    }
                    pos[m].clear();
                }
                prime[p]=false;
            }
        }
        return n-1;
    }
};