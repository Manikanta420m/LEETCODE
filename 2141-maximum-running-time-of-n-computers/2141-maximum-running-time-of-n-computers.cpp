class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long ans=0;
        sort(batteries.rbegin(),batteries.rend());
        long long sm=accumulate(batteries.begin()+n,batteries.end(),0LL);
        int m=batteries.size();
        for(int i=n-1;i>=1;i--){
           int num=n-i;
           int diff=batteries[i-1]-batteries[i];
           int req=diff*num;
           if(sm>=req){
            batteries[i]=batteries[i-1];
            sm-=req;
           }
           else{
            return batteries[i]+(sm/num);
           }
        }
        return batteries[0]+(sm/n);
    }
};