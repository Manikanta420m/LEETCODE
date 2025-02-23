class Solution {
public:
     
     void rec(int idx_i,int idx_j,int n,string s,vector<string>&ans){
       if(idx_i==n && idx_j==n){
        ans.push_back(s);
        return ;
       }
       if(idx_i<n)rec(idx_i+1,idx_j,n,s+'(',ans);
       if(idx_j<idx_i)rec(idx_i,idx_j+1,n,s+')',ans);
     }

    vector<string> generateParenthesis(int n) {
       vector<string>ans;
       string s;
       rec(0,0,n,s,ans);
       return ans; 
    }
};