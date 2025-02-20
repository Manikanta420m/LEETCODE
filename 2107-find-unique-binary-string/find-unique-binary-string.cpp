class Solution {
public:
    string res="";
    bool rec(string &ans,vector<string>& nums,unordered_set<string>&st){
        if(ans.size()==nums[0].size()){
           if(st.count(ans)==0){
            res=ans;
            return true;
           }
           return false;
        }

        ans.push_back('0');
        if( rec(ans,nums,st))return true;
        ans.pop_back();

        ans.push_back('1');
        if( rec(ans,nums,st))return true;
        ans.pop_back();

        return false;
    }

    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string>st(nums.begin(),nums.end());
        string ans="";
        rec(ans,nums,st);
        return res;
    }
};