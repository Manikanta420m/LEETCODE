class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sm1=accumulate(nums1.begin(),nums1.end(),0LL);
        long long sm2=accumulate(nums2.begin(),nums2.end(),0LL);
        int c1=count(nums1.begin(),nums1.end(),0);
        int c2=count(nums2.begin(),nums2.end(),0);
        if(c1==0 and c2==0)return sm1==sm2?sm1:-1;
        if(c1==0)return sm1>=sm2+c2?sm1:-1;
        if(c2==0)return sm2>=sm1+c1?sm2:-1;
        return max(sm1+c1,sm2+c2);
    }
};