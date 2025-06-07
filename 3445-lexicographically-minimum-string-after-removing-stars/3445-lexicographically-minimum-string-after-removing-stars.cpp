class Solution {
public:
    string clearStars(string s) {
        int n=s.size();
        string res="",ans="";
        map<char,vector<int>>mp;
        for(int i=0;i<n;i++){
            if(s[i]=='*'){
               for(char ch='a';ch<='z';ch++){
                    if(!mp[ch].empty()){
                    int idx= mp[ch].back();
                    res[idx]='#';
                    mp[ch].pop_back();
                    break;
                    }
               }
            }
            else{
               res+=s[i];
               mp[s[i]].push_back(res.size()-1);
            }
        }
        for(auto i:res){
            if(i!='#')ans+=i;
        }
     return ans;
    }
};