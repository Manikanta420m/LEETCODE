class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        vector<int>ans;
        unordered_set<int>st(friends.begin(),friends.end());
        for(auto i:order){
            if(st.contains(i))ans.push_back(i);
        }
        return ans;
    }
};