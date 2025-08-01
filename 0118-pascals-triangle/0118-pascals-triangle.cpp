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
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int i=1;i<=numRows;i++){
            ans.push_back(generateRow(i));
        }
        return ans;
    }
};