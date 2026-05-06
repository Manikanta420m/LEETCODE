class Solution {
public:
    void fill(vector<vector<char>>&res,int c,int x,int y){
        while(c){
            res[x][y]='#';
            x--;
            c--;
        }
    }
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n=box.size();
        int m=box[0].size();
        vector<vector<char>>res(m,vector<char>(n,'.'));
        for(int i=0;i<n;i++){int c=0;
            for(int j=0;j<m;j++){
                if(box[i][j]=='#')c++;
                else if(box[i][j]=='*'){
                      res[j][n-i-1]='*';
                      fill(res,c,j-1,n-i-1);
                      c=0;
                }
            }
            if(c>0)fill(res,c,m-1,n-i-1);
        }return res;
    }
};