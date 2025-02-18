class Solution {
public:
    int maxi(int &mid,vector<vector<int>>& mat){
        int n=mat.size();
        int maxi=-1,ind=-1;
        for(int i=0;i<n;i++){
            if(mat[i][mid]>maxi){
                maxi=mat[i][mid];
                ind=i;
            }
        }return ind;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int l=0,r=m-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            int row=maxi(mid,mat);
            int left=mid>0?mat[row][mid-1]:-1;
            int right=mid<m-1?mat[row][mid+1]:-1;
            if(mat[row][mid]>left && mat[row][mid]>right)return {row,mid};
            else if(mat[row][mid]<left)r=mid-1;
            else l=mid+1;
        }return {-1,-1};
    }
};