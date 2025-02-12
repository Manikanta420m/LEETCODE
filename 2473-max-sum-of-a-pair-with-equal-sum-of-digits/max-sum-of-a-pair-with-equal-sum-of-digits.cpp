class Solution {
public:
    int maximumSum(vector<int>& nums) {
      int f[83]={0};
        int ans=-1;
        for(auto &i:nums){
          int n=i;
          int ansi=0;
          while(n!=0){
              ansi+=n%10;
              n/=10;
          }
           if(f[ansi]>0)
               ans=max(ans,f[ansi]+i);
            f[ansi]=max(f[ansi],i);
         }return ans;  
    }
};