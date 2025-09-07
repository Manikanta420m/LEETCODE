class Solution {
private:
    long long cnt(int l){
        if(l==1)return 2;
        if(l&1)return 1LL<<((l-1)/2);
        else return 1LL<<((l/2)-1);
    }
public:
    int countBinaryPalindromes(long long n) {
        if(n==0)return 1;
        if(n==1)return 2;

        vector<int>bits;
        long long temp=n;
        while(temp>0){
            bits.push_back(temp&1);
            temp>>=1;
        }
        reverse(bits.begin(),bits.end());
        int m=bits.size();

        long long ans=0;
        for(int l=1;l<m;l++){
           ans+=cnt(l);
        }

        int half=(m+1)/2;

        long long firVal=0;
        for(int i=0;i<half;i++){
            firVal=(firVal<<1)|bits[i];
        }

        long long start=1LL<<(half-1);

        if(firVal>start)ans+=(firVal-start);

        long long pal=0;

        for(int i=0;i<half;i++)pal=(pal<<1)|bits[i];
        int revStart=(m%2==1)?half-2:half-1;
        for(int i=revStart;i>=0;i--)pal=(pal<<1)|bits[i];
        if(pal<=n)ans++;
        return ans;
    }
};