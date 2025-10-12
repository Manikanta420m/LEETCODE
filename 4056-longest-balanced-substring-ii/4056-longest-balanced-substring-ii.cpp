class Solution {
private:
    void cal2(string s,char c1,char c2,int &ans){
        unordered_map<int,int>mp;
        mp[0]=-1;
        int x=0,y=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==c1)x++;
            else if(s[i]==c2)y++;
            else{
                mp.clear();
            }
            if(mp.count(x-y))ans=max(ans,i-mp[x-y]);
            else mp[x-y]=i;
        }
    }
public:
    int longestBalanced(string s) {
        int cnt=1,ans=1;
        for(int i=1;i<s.size();i++){
           if(s[i]==s[i-1])cnt++;
           else cnt=1;
           ans=max(ans,cnt);
        }
        cal2(s,'a','b',ans);
        cal2(s,'a','c',ans);
        cal2(s,'c','b',ans);
        int a=0,b=0,c=0;
        map<pair<int,int>,int>mp;
        mp[{0,0}]=-1;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a')a++;
            else if(s[i]=='b')b++;
            else c++;
            int x=a-b,y=a-c;
            if(mp.count({x,y})){
               ans=max(ans,i-mp[{x,y}]);
            }
            else{
                mp[{x,y}]=i;
            }
        }
        return ans;
    }
};