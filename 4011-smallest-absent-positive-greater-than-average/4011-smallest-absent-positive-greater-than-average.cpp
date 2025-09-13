class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        double avg=accumulate(nums.begin(),nums.end(),0.0)/nums.size();
        unordered_set<int>st(nums.begin(),nums.end());
        if(ceil(avg)==floor(avg))avg++;
        for(int i=max(1,(int)ceil(avg));;i++){
             if(!st.contains(i))return i;
        }
        return -1;
    }
};