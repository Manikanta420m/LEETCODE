class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        int l=0,r=0;
        while(l<n and r<m){
            if(nums1[l]==nums2[r])return nums1[l];
            if(nums1[l]<nums2[r])l++;
            else r++;
        }
        return -1;
    }
};