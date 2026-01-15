class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& H, vector<int>& V) {
        int mxh=1,mxv=1;
        sort(H.begin(),H.end());
        sort(V.begin(),V.end());
        int tH=1,tV=1;
        int n1=H.size();
        int m1=V.size();
        for(int i=1;i<max(n1,m1);i++){
            if(i<n1 and H[i]-H[i-1]==1)tH++;
            else if(i<n1){
                mxh=max(mxh,tH);
                tH=1;
            }
            if(i<m1 and V[i]-V[i-1]==1)tV++;
            else if(i<m){
                mxv=max(mxv,tV);
                tV=1;
            }
        }
        mxh=max(mxh,tH);
        mxv=max(mxv,tV);
        return (min(mxh,mxv)+1)*(min(mxh,mxv)+1);
    }
};