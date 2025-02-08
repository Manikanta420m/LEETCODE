class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int n=nums.size();
       // sort(nums.begin(),nums.end());
        int l=1,h=*max_element(nums.begin(),nums.end());
        int ans=h;
        while(l<=h){
            int mid=l+(h-l)/2,ops=0;
            for (int i:nums){
                ops+=(i-1)/mid;
                if(ops>maxOperations)break;
            }
            if(ops<=maxOperations){
                ans=mid;
                h=mid-1;
            }
            else l=mid+1;
        }return ans;
    }
};