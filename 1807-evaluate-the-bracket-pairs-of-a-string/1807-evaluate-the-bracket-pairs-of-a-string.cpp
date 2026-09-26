class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string>mp;
        for(auto i:knowledge){
            mp[i[0]]=i[1];
        }
        bool f=false;
        string ans="",res="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                f=true;
            }
            else if(s[i]==')'){
                if(mp.count(res))ans+=mp[res];
                else ans+='?';
                res="";
                f=false;
            }
            else if(f)res+=s[i];
            else ans+=s[i];
        }
        return ans;
    }
};