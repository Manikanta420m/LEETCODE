class Solution {
    const int M=1e9+7;
private:
    long long power(long long a,long long b){
        long long ans=1;
        while(b>0){
            if(b&1)ans=(a*ans)%M;
            a=(a*a)%M;
            b>>=1;
        }
        return ans;
    }
    long long ncr(int n,int r,vector<long long>& fact, vector<long long>& invfact){
        if(r<0 or r>n)return 0;
        return fact[n]*invfact[r]%M*invfact[n-r]%M;
    }
public:
    int countValidSequences(int n, int k) {
        vector<long long>fact(n+1),invfact(n+1);
        fact[0]=1;
        for(int i=1;i<=n;i++){
            fact[i]=(fact[i-1]*i)%M;
        }
        invfact[n]=power(fact[n],M-2);
        for(int i=n;i>=1;i--){
            invfact[i-1]=(invfact[i]*i)%M;
        }
        long long tot=ncr(n-1,k-1,fact,invfact);
        long long odd=0;
        if((n-k)%2==0){
            int N=(n-k)/2;
            odd=ncr(N+k-1,k-1,fact,invfact);
        }
        return (tot-odd+M)%M;
    }
};