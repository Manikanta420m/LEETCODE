class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans=0;
        int a=0,b=0,c=0,j=0;
        bool f=true;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a')a++;
            else if(s[i]=='b')b++;
            else c++;
            if((a==0 or b==0 or c==0) and f)continue;
            while(j<i and a>0 and b>0 and c>0){
                if(s[j]=='a')a--;
                else if(s[j]=='b')b--;
                else c--;
                j++;
                f=false;
            }
            ans+=(j);
        }
        return ans;
    }
};