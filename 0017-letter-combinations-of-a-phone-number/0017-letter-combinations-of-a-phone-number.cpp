class Solution {
private:
    void backtrack(int idx,string cur,string &digits,vector<string>&ans,vector<string>&v){
        if(idx==digits.length()){
            ans.push_back(cur);
            return;
        }
        int num=digits[idx]-'0';
        string str=v[num];
        int str_len=str.length();
        for(int i=0;i<str_len;i++){
            cur.push_back(str[i]);
            backtrack(idx+1,cur,digits,ans,v);
            cur.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        if(digits.length()==0)return ans;
        vector<string>v={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        backtrack(0,"",digits,ans,v);
        return ans;
    }
};