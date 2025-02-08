class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
       long long maxi=accumulate(nums.begin(),nums.end(),0); 
       if(k==1)return (int)maxi;
       long long maxe=*max_element(nums.begin(),nums.end());
       long long l=maxe,r=maxi;
       int n=nums.size();
       int ansi=0;
       while(l<=r){
         long long mid=l+(r-l)/2;
         long long c=1,ans=0;
         for(int i=0;i<n;i++){
            if(nums[i]+ans<=mid){
                ans+=nums[i];
            }
            else {
                c++;
                ans=nums[i];
            }
         }
        // if(ans>0)c++;
         if(c<=k){
            ansi=mid;
            r=mid-1;
         }
         else l=mid+1;
       }
       return ansi;
    }
};