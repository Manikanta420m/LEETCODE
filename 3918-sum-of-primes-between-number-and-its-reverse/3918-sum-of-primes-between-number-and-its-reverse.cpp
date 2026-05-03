class Solution {
public:
    int rev(int n){
        int temp=0;
        while(n>0){
            temp=temp*10+n%10;
            n/=10;
        }
        return temp;
    }

    int sumOfPrimesInRange(int n) {
        int r=rev(n);
        int mini=min(r,n);
        int maxi=max(n,r);
        if(maxi<2)return 0;
        vector<bool>primes(maxi+1,true);
        primes[0]=primes[1]=false;
        for(int i=2;i*i<=maxi;i++){
            if(primes[i]){
                for(int j=i*i;j<=maxi;j+=i){
                    primes[j]=false;
                }
            }
        }
        int sm=0;
        for(int i=mini;i<=maxi;i++){
           if(primes[i])sm+=i;
        }
        return sm;
    }
};