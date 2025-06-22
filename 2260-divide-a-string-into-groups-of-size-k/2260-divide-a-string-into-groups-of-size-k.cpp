class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        // vector<string>ans;
        // string res="";
        // for(int i=0;i<s.size();i++){
        //    res.push_back(s[i]);
        //    if(res.size()==k){ans.push_back(res);res="";}
        // }
        // if(res.size()){
        //     while(res.size()<k)res.push_back(fill);
        //     ans.push_back(res);
        // }
        // return ans;
        auto [q, r]=div(s.size(), k);
        vector<string> ans(q+(r>0)); 
        for (int i=0; i<q; i++){
            ans[i]=s.substr(i*k, k);
        }
        if (r>0){
            ans.back()=s.substr(q*k);
            ans.back()+=string(k-r, fill);
        }
        return ans;

    }
};