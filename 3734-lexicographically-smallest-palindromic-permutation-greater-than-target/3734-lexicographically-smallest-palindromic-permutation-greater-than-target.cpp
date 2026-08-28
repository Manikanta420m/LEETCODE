class Solution {
public:
    string ans;
    bool solve(int i,string s,vector<int>&cnt,string target,char mid,bool flag){
        if(s.size()==target.size()/2){
            string res=s;
            if(target.size()&1){
                res+=mid;
            }
            reverse(s.begin(),s.end());
            res+=s;
            if(res>target){ans=res;return true;}
            return false;
        }
        for(int j=0;j<26;j++){
            if(cnt[j]==0)continue;
            if(!flag and ('a'+j)<target[i])continue;
            cnt[j]--;
            s+='a'+j;
            bool newFlag=flag;
            if(target[i]<'a'+j){
                newFlag=true;
            }
            if(solve(i+1,s,cnt,target,mid,newFlag))return true;
            s.pop_back();
            cnt[j]++;
        }
        return false;
    }
    string lexPalindromicPermutation(string s, string target) {
       ans = "";
       vector<int>cnt(26,0);
       for(auto i:s){
        cnt[i-'a']++;
       }
       int odd=0;
       char mid=' ';
       for(int i=0;i<26;i++){
        if(cnt[i]&1){
            mid='a'+i;
            odd++;
        }
        if(odd>1)return "";
        cnt[i]/=2;
       }
       solve(0,"",cnt,target,mid,false);
       return ans;
    }
};