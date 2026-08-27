class Solution {
public:
    string ans="";
    
    bool func(vector<char>&path,vector<int>&cnt,string &target,bool big){
        int n=target.size();
        if(!ans.empty())return true;
        if(path.size()==n){
            if(big){
                ans=string(path.begin(),path.end());
            }
            return false;
        }
        int i=path.size();
        for(int c=0;c<26;c++){
           if(cnt[c]==0)continue;
           if(!big and c+'a'<target[i])continue;
           path.push_back(c+'a');
           cnt[c]--;
           bool nB=big||(c+'a'>target[i]);
           if(func(path,cnt,target,nB))return true;
           path.pop_back();
           cnt[c]++;
        }
        return false;
    }

    string lexGreaterPermutation(string s, string target) {
        vector<int>cnt(26,0);
        for(auto i:s)cnt[i-'a']++;
        ans="";
        vector<char>path;
        func(path,cnt,target,false);
        return ans;
    }
};