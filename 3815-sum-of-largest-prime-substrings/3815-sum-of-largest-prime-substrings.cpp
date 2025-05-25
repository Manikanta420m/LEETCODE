class Solution {
public:
    bool isprime(long long n){
        if(n<2)return false;
        for(long long i=2;i*i<=n;i++){
            if(n%i==0)return false;
        }return true;
    }
    long long sumOfLargestPrimes(const string &s) {
        vector<long long>cont;
        for(int i=0;i<s.size();i++){
            long long num=0;
            for(int j=i;j<s.size();j++){
                num=num*10+(s[j]-'0');
                if(isprime(num))cont.emplace_back(num);
            }
        }
        sort(cont.begin(),cont.end());
        cont.erase(unique(cont.begin(),cont.end()),cont.end());
        long long m=cont.size();
        if(m<3)return accumulate(cont.begin(),cont.end(),0LL);
        return cont[m-1]+cont[m-2]+cont[m-3];
    }
};