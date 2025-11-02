class Solution {
public:
    long long d1,d2,r1,r2;
    bool check(long long mid){
       long long t1=mid-(mid/r1);
       long long t2=mid-(mid/r2);
       long long t3=mid-(mid/((r1*r2)/__gcd(r1,r2)));
       return d1<=t1 and d2<=t2 and d1+d2<=t3;
    }
    long long minimumTime(vector<int>& d, vector<int>& r) {
        d1=d[0],d2=d[1],r1=r[0],r2=r[1];
        long long low=0,high=1e10;
        while(low<=high){
            long long mid=low+(high-low)/2;
            if(check(mid)){
               high=mid-1;
            }
            else{
               low=mid+1;
            }
        }
        return low;
    }
};