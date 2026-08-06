#define ll long long 
class Solution {
public:
    int smallestNumber(int n, int t) {
         ll x2=n;
        while(1){
            ll ans=1;
            ll x=x2;
            while(x>0){
                ll res=x%10;;
                x/=10;
                ans*=res;
            }
            if(ans%t==0)return x2;
            x2++;
        }
    
    }
};