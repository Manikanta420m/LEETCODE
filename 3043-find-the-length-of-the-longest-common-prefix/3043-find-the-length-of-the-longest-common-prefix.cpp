class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string>st;
        for(auto i:arr1){
            string s=to_string(i);
            string temp="";
            for(auto j:s){
                temp.push_back(j);
                st.insert(temp);
            }
        }
        int ans=0;
        for(auto i:arr2){
            string s=to_string(i);
            string temp="";
            for(auto j:s){
                temp.push_back(j);
                if(st.count(temp))ans=max(ans,(int)temp.size());
                else break;
            }
        }
        return ans;
    }
};