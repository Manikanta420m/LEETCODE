#define ll long long 
class Solution {
public:
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};
    long long minCost(int m, int n, vector<vector<int>>& penalty) {
        vector<vector<vector<ll>>>dist(m,vector<vector<ll>>(n,vector<ll>(2,LLONG_MAX)));
        priority_queue<tuple<ll,int,int,int>,vector<tuple<ll,int,int,int>>,greater<>>pq;
        dist[0][0][1]=1;
        pq.push({1,0,0,1});
        while(!pq.empty()){
            auto [cost,i,j,f]=pq.top();
            pq.pop();
            if(cost>dist[i][j][f])continue;
            if(i==m-1 and j==n-1)return cost;
            int nf=f^1;
            if(cost+penalty[i][j]<dist[i][j][nf]){
                dist[i][j][nf]=cost+penalty[i][j];
                pq.push({dist[i][j][nf],i,j,nf});
            }
            for(int d=0;d<4;d++){
                int nx=i+dx[d];
                int ny=j+dy[d];
                if(nx<0 or nx>=m or ny<0 or ny>=n)continue;
                bool ok=f?(d<2):(d>=2);
                ll ncost=cost+1LL*(nx+1)*(ny+1)+(ok?0:penalty[i][j]);
                if(ncost<dist[nx][ny][nf]){
                    dist[nx][ny][nf] = ncost;
                    pq.push({ncost, nx, ny, nf});
                }
            }
        }
        return -1;
    }
};