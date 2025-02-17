class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
       int l=1;
       int r=*max_element(nums.begin(),nums.end());
       while(l<=r){
         int mid=l+(r-l)/2;
         int ans=0;
         for(int i=0;i<nums.size();i++){
            //ans+=(min(nums[i]/mid,mid-nums[i]/mid));
            ans+=((nums[i]+mid-1)/mid);
         }
         if(ans<=threshold)r=mid-1;
         else l=mid+1;
       }return l;
    }
};