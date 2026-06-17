class Solution {
public:
    char processStr(string s, long long k) {
        int n=s.size();
        vector<long long>Len(1e5,0);
        long long l=0;
        for(int i=0;i<n;i++){
            char ch=s[i];
            if(ch=='*')l-=(l>0);
            else if(ch=='#')l<<=1;
            else if(ch=='%'){Len[i]=l;continue;}
            else l++;
            Len[i]=l;
        }
        if(l-1<k)return '.';
        for(int i=n-1;i>=0;i--){
            char ch=s[i];
            l=Len[i];
            if(l==0)continue;
            if(ch=='#'){
                if(k>=l/2)k-=(l/2);
            }
            else if(ch=='%')k=l-1-k;
            else if(ch=='*')continue;
            else {
                if(k==l-1)return ch;
            }
        }
        return '.';
    }
};