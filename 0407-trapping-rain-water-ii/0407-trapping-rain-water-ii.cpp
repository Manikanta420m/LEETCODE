class Solution {
    #define pip pair<int,pair<int,int>>

    bool isValid(int &x,int &y,int &m,int &n){
        return (x>=0 && x<m && y>=0 && y<n);
    }
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m=heightMap.size();
        int n=heightMap[0].size();
        if(m<3 || n<3)return 0;
        priority_queue<pip,vector<pip>,greater<pip>>minheap;
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || i==m-1 || j==0 || j==n-1){
                    minheap.push((make_pair(heightMap[i][j],make_pair(i,j))));
                    vis[i][j]=true;
                }
            }
        }
        int lvl=0;
        int trapped=0;
        vector<int>dir={-1,0,1,0,-1};
        while(!minheap.empty()){
            pip cur=minheap.top();
            minheap.pop();
            int height=cur.first;
            int x=cur.second.first;
            int y=cur.second.second;
            lvl=max(lvl,height);
            for(int i=0;i<4;i++){
                int X=x+dir[i];
                int Y=y+dir[i+1];
                if(isValid(X,Y,m,n) && !vis[X][Y]){
                    vis[X][Y]=true;
                    minheap.push(make_pair(heightMap[X][Y],make_pair(X,Y)));
                    if(heightMap[X][Y]<lvl)
                        trapped+=lvl-heightMap[X][Y];
                }

            }
        }return trapped;
    }
};