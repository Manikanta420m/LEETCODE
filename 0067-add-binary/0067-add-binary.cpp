class Solution {
public:
    string addBinary(string a, string b){
       string ans="";
       int n=a.size(),m=b.size();
       int rem=0;
       while(n>0 or m>0){
            int l=0,r=0;
            if(n>0){l=a[n-1]-'0';n--;}
            if(m>0){r=b[m-1]-'0';m--;}
            int sm=l+r+rem;
            if(sm==0){ans.push_back('0');rem=0;}
            else if(sm==1){ans.push_back('1');rem=0;}
            else if(sm==2){ans.push_back('0');rem=1;}
            else {ans.push_back('1');rem=1;}
       }
       if(rem>0)ans.push_back('1');
       reverse(ans.begin(),ans.end());
       return ans;
    }
};