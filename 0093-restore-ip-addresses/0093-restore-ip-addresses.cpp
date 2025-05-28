class Solution {
private:
    void backtrack(int idx,string cur,string &s,vector<string>&ans,int dots){
        if(dots==4 and idx==s.length()){
            ans.push_back(cur.substr(0,cur.length()-1));
            return;
        }
        if(dots>4)return;
        for(int i=idx;i<min((int)s.length(),idx+3);i++){
            if(stoi(s.substr(idx,i-idx+1))<256 and (s[idx]!='0' || idx==i)){
                backtrack(i+1,cur+s.substr(idx,i-idx+1)+".",s,ans,dots+1);
            }
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string>ans;
        if(s.length()>12)return ans;
        backtrack(0,"",s,ans,0);
        return ans;
    }
};