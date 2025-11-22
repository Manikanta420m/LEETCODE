class Solution {
public:
    long long sumUpTo(long long x){
        return (x) * (x+1) / 2;
    }
    vector<int> lexSmallestNegatedPerm(int n, long long target) {
        long long S = sumUpTo(n);
        if (target < -S || target > S) return {};

        vector<int> v;
        for(int i = n; i>=1; i--){
            //can I be negative?
            if(sumUpTo(i-1) - i >= target){
                target+=i;
                v.push_back(-i);
            }   
            else{
                //i must be positive
                target-=i;
                v.push_back(i);
            }
        }
        if (target != 0)return {};
        //smallest lexicographic
        sort(v.begin(), v.end());
        return v;
    }
};