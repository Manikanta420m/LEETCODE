class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<pair<int,int>>pr;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0)pr.push_back(make_pair(i,j));
            }
        }
        for(auto it:pr){
            for(int i=0;i<m;i++)matrix[it.first][i]=0;
            for(int i=0;i<n;i++)matrix[i][it.second]=0;
        }
    }
};