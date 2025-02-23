class Solution {
public:
    
    void solve(int ind,string digits,string res,vector<string>&ans,string mapping[]){
        if(res.size()==digits.size()){
            ans.push_back(res);
            return;
        }
        int num=digits[ind]-'0';
        string s=mapping[num];
        for(int i=0;i<s.size();i++){
            res.push_back(s[i]);
             solve(ind+1,digits,res,ans,mapping);
             res.pop_back();
        }
       return;
    }

    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        if(digits.size()==0)return ans;
        string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string res;
        solve(0,digits,res,ans,mapping);
        return ans;
    }
};