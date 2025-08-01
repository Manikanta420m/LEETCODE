class Solution {
private:
    vector<int>generateRow(int row){
        vector<int>ans;
        ans.push_back(1);
        int temp=1;
        for(int i=1;i<row;i++){
            temp*=(row-i);
            temp/=i;
            ans.push_back(temp);
        }
        return ans;
    }
public:
    // vector<vector<int>> generate(int numRows) {
    //     vector<vector<int>>ans;
    //     for(int i=1;i<=numRows;i++){
    //         ans.push_back(generateRow(i));
    //     }
    //     return ans;
    // }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> a(numRows);
        for(int i=0; i<numRows; i++){
            a[i].assign(i+1, 1);// exact allocation once
            for(int&& j=1; j<=i/2; j++){
                  a[i][i-j]=a[i][j]=a[i-1][j-1]+a[i-1][j];
                        
            }              
        }
        return a;
    }
};