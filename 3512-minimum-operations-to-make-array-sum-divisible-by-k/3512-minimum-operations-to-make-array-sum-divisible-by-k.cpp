class Solution {
public:
    int minOperations(vector<int>& a, int k) {
        long long suma=accumulate(a.begin(),a.end(),0);
        return suma%k;
    }
};