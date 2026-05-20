class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
       vector<int>ans;
       unordered_set<int>st;
       int n=A.size();
       for(int i=0;i<n;i++){
           st.insert(A[i]);
           st.insert(B[i]);
           ans.push_back(2*(i+1)-st.size());
       }return ans;
    }
};
