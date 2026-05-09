class Solution {
private:
    void solve(vector<int>&temp,int k){
        int n=temp.size();
        k%=n;
        reverse(temp.begin(),temp.end());
        reverse(temp.begin(),temp.begin()+k);
        reverse(temp.begin()+k,temp.end());
    }
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        vector<vector<int>>ans;
        int n=grid.size(),m=grid[0].size();
        int x=n,y=m;
        for(int i=0;i<min(n,m)/2;i++){
            vector<int>temp;
            for(int j=i;j<x;j++){
                temp.push_back(grid[j][i]);
            }
            for(int j=i+1;j<y-1;j++){
                temp.push_back(grid[x-1][j]);
            }
            for(int j=x-1;j>=i;j--){
                temp.push_back(grid[j][y-1]);
            }
            for(int j=y-2;j>i;j--){
                temp.push_back(grid[i][j]);
            }

            if(temp.size()!=0)solve(temp,k);
            int cnt=0;
            for(int j=i;j<x;j++){
                grid[j][i]=temp[cnt];
                cnt++;
            }
            for(int j=i+1;j<y-1;j++){
                grid[x-1][j]=temp[cnt];
                cnt++;
            }
            for(int j=x-1;j>=i;j--){
                grid[j][y-1]=temp[cnt];
                cnt++;
            }
            for(int j=y-2;j>i;j--){
                grid[i][j]=temp[cnt];
                cnt++;
            }
            x--,y--;
        }
        return grid;
    }
};