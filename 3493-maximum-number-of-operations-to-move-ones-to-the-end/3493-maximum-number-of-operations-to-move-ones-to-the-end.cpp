class Solution {
public:
    int maxOperations(string s) {
        int ans=0,c=0;
        int n=s.size();
        if(n==1)return 0;
        bool f=false;
        for(int i=n-2;i>=0;i--){
           if(s[i]=='1' and s[i+1]=='0')f=true;
           if(f and s[i]=='1'){
            if(s[i+1]!='1')c++;
             ans+=c;
           }
        }
        return ans;
    }
};