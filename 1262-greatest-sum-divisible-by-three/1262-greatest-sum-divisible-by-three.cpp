class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
       int ans=0,sm=0;
       int min11=INT_MAX,min12=INT_MAX,min21=INT_MAX,min22=INT_MAX;
       for(int i=0;i<nums.size();i++){
         if(nums[i]%3==1){
            if(min12>nums[i]){
                min11=min12;
                min12=nums[i];
            }
            else if(min11>nums[i])min11=nums[i];
         }
         if(nums[i]%3==2){
            if(min22>nums[i]){
                min21=min22;
                min22=nums[i];
            }
            else if(min21>nums[i])min21=nums[i];
         }
         sm+=nums[i];
       } 
       if(sm%3==1){
         int s1=min12;
         int s2=(min21==INT_MAX or min22==INT_MAX?INT_MAX:min21+min22);
         sm-=min(s1,s2);
       }
       else if(sm%3==2){
         int s1=min22;
         int s2=(min11==INT_MAX or min12==INT_MAX?INT_MAX:min11+min12);
         sm-=min(s1,s2);
       }
       return sm;
    }
};