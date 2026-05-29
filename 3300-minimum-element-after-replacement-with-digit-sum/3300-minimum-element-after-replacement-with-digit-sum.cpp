class Solution {
public:
    int minElement(vector<int>& nums) {
      int   sum=0;
      int   mini=INT_MAX;
        for(auto i:nums){
            sum=0;
            while(i!=0){sum+=(i%10);i/=10;}
            mini=min(sum,mini);
        }
        return mini;
    }
};