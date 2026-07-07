class Solution {
public:
    long long sumAndMultiply(int n) {
        long long ans=0,num=0;
        string s=to_string(n),s1;
        for(auto ch:s){
            if(ch!='0')s1.push_back(ch);
        }
        if(s1.empty())return 0;
        ans=stoll(s1);
        for(auto ch:s1)num+=(ch-'0');
        return ans*num;
    }
};