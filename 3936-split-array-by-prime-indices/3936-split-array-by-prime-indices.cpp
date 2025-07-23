class Solution {
public:
    vector<int>sieve(int n){
        vector<int>v(n+1,1);
        v[0]=0;
        v[1]=0;
        for(int i=2;i<=sqrt(n);i++){
            if(v[i]){
                for(int j=i*i;j<=n;j+=i){
                    v[j]=0;
                }
            }
        }
        return v;
    }
    long long splitArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>p=sieve(n);
        long long sm1=0,sm2=0;
        for(int i=0;i<n;i++){
            if(p[i])sm1+=nums[i];
            else sm2+=nums[i];
        }
        return abs(sm1-sm2);
    }
};