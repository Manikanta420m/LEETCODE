class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string>ans;
        string res="";
        for(int i=0;i<s.size();i++){
           res.push_back(s[i]);
           if(res.size()==k){ans.push_back(res);res="";}
        }
        if(res.size()){
            while(res.size()<k)res.push_back(fill);
            ans.push_back(res);
        }
        return ans;
    }
};