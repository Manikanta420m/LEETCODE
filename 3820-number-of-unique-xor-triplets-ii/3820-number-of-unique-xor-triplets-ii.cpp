class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        vector<bool>poss(3001,false);
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                poss[nums[i]^nums[j]]=true;
            }
        }
        vector<bool>newposs(3001,false);
        for(int i=0;i<=3000;i++){
            for(int j=0;j<n;j++){
                if(((i^nums[j])<=3000) && poss[i^nums[j]]){newposs[i]=true;}
            }
        }
        return count(newposs.begin(),newposs.end(),true);
    }
};