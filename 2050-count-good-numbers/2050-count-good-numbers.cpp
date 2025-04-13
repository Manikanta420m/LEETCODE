class Solution {
public:
    const int M=1e9+7;
    
    long long power(long long base,long long exp){
        long long res=1;
        while(exp>0){
            if(exp%2==1)res=(res*base)%M;
            base=(base*base)%M;
            exp/=2;
        }return res;
    }

    int countGoodNumbers(long long n) {
        long long ans=(power(5,(n+1)/2)*power(4,n/2))%M;
        return ans;
    }
};  