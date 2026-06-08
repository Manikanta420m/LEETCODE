class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        if(n==1)return nums;
        int l=0,m=0,sz=n;
        vector<int>v;
        for(auto i:nums){
            if(i<pivot)nums[l++]=i;
            else if(i>pivot)v.push_back(i),sz--;
            else m++;
        }
        auto it=nums.begin()+l;
        fill(it,it+m,pivot);
        copy(v.begin(),v.end(),it+m);
        return nums;
    }
};