class Solution {
public:
    string discountPrices(string s, int discount) {
        string ans="";
        int n=s.size();
        s=" "+s;
        for(int i=1;i<=n;i++){
            if(s[i]=='$' and s[i-1]==' '){
                int j=i+1;
                string temp;
                bool f=true;
                while(j<=n and s[j]!=' '){
                  if(s[j]<'0' or s[j]>'9')f=false;
                  temp+=s[j];
                  j++;
                }
                if(!f or temp.empty())ans+="$"+temp;
                else {
                    long long num=stoll(temp);
                    long double res=(num*discount)/100.0;
                    long double x=(num-res);
                    string xe=to_string(x);
                    int cnt=4;
                    while(cnt--)
                      xe.pop_back();
                    string str="$"+xe;
                    ans+=str;
                }
                i=j-1;
            }
            else{
                ans+=s[i];
            }
        }
        return ans;
    }
};