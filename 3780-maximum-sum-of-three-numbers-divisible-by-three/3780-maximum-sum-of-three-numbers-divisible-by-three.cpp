class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int ans=0;
        int on=0,tw=0,th=0;
        vector<int>ones,twos,thrs;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%3==1){
                on=max(on,nums[i]);
                ones.push_back(nums[i]);
            }
            else if(nums[i]%3==2){
                tw=max(tw,nums[i]);
                twos.push_back(nums[i]);
            }
            else {
                th=max(th,nums[i]);
                thrs.push_back(nums[i]);
            }
        }
        sort(thrs.rbegin(),thrs.rend());
        sort(twos.rbegin(),twos.rend());
        sort(ones.rbegin(),ones.rend());
        int maxi=0;
        if(ones.size()>=3)maxi=max(maxi,accumulate(ones.begin(),ones.begin()+3,0));
        if(twos.size()>=3)maxi=max(maxi,accumulate(twos.begin(),twos.begin()+3,0));
        if(thrs.size()>=3)maxi=max(maxi,accumulate(thrs.begin(),thrs.begin()+3,0));
        if(on!=0 and tw!=0 and th!=0){
            maxi=max(maxi,th+tw+on);
        }
        return maxi;
    }
};