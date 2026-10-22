class Solution {
public:
    int MAXI=1e9;
    int minOperations(vector<int>& nums) {
       int mini=0;
        int ans=0;
        int n=nums.size();
        bool f=true;
        for(int i=0;i<n;i++){
            if(i!=nums[i]){
                f=false;
                break;
            }
        }
        mini+=1;
        if(f)return 0;
        bool f1=true;
        int k=nums[0];
        for(int i=0;i<n;i++){
            if(nums[i]!=(k+i)%n){
                f1=false;
                break;
            }
        }
        if(f1)return min(n-k,k+2);
        f1=true;
        k=nums[0];
        for(int i=0;i<n;i++){
            if(nums[i]!=(k-i+n)%n){
                f1=false;
                break;
            }
        }
        if(f1)return min(n-k,k+2);
        return -1;
    }
};