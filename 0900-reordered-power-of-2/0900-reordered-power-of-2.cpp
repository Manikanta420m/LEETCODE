class Solution {
public:
    unordered_set<string>st;
    Solution(){
    for(int i=1;i<=1e9;i*=2){
        string s=to_string(i);
        sort(s.begin(),s.end());
        st.insert(s);
      }
    }
public:
    bool reorderedPowerOf2(int n) {
        string s=to_string(n);
        sort(s.begin(),s.end());
        return st.find(s)!=st.end();
    }
};