class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool>prime(right+1,true);
        prime[0]=prime[1]=false;
        for(int i=2;i*i<=right;i++){
            if(prime[i]){
                for(int j=i*i;j<=right;j+=i)prime[j]=false;
            }
        }
        vector<int>p;
        for(int i=left;i<=right;i++){
            if(prime[i]){
                p.push_back(i);
            }
        }
        if(p.size()<2)return {-1,-1};
        int gap=INT_MAX;
        vector<int>ans={-1,-1};
        for(int i=1;i<p.size();i++){
            int g=p[i]-p[i-1];
            if(g<gap){
                gap=g;
                ans={p[i-1],p[i]};
            }
        }return ans;
    }
};