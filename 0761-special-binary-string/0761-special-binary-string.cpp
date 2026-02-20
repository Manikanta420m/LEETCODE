class Solution {
public:
    string makeLargestSpecial(string s) {
        int i=0,c=0;
        vector<string>res;
        for(int j=0;j<s.size();j++){
           c+=(s[j]=='1')?1:-1;
           if(c==0){
            res.push_back('1'+makeLargestSpecial(s.substr(i+1,j-i-1))+'0');
            i=j+1;
           }
        }
        sort(res.rbegin(),res.rend());
        string ans;
        for(auto i:res)ans+=i;
        return ans;
    }
};