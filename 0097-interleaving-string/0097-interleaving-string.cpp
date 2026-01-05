class Solution {
private:
    bool solve(int i,int j,int k,string &s1, string &s2, string &s3){
        if(k==0)return true;
        if(i>0 and j>0 and s1[i-1]==s2[j-1] and s1[i-1]==s3[k-1]){
            return (solve(i-1,j,k-1,s1,s2,s3) or solve(i,j-1,k-1,s1,s2,s3));
        }
        else if(i>0 and s1[i-1]==s3[k-1]){
            return solve(i-1,j,k-1,s1,s2,s3);
        }
        else if(j>0 and s2[j-1]==s3[k-1]){
            return solve(i,j-1,k-1,s1,s2,s3);
        }
        else return false;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.size();
        int m=s2.size();
        int k=s3.size();
        if(k<n+m)return false;
        return solve(n,m,k,s1,s2,s3);
    }
};