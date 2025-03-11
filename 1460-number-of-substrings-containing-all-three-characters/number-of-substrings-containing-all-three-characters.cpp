class Solution {
public:
    int numberOfSubstrings(string s) {
       int la=0,lb=0,lc=0;
       int l=0,r=0,mini=0,sum=0,a=0,b=0,c=0;
       for(int i=0;i<s.length();i++){
        int ani=s[i]-'a';
        if(ani==0){
            la=i;
            a++;
        }
        if(ani==1){lb=i;
        b++;
        }
        if(ani==2){lc=i;
        c++;
        }
        if(a>0&&b>0&&c>0){
            mini=min(min(la,lb),lc);
            sum+=mini+1;
        }
       }
       return sum;
    }
};