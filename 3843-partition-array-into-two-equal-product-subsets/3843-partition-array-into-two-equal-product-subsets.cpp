class Solution {
public:
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        __int128 t_mul=1,mul=1;
        for(int i=0;i<nums.size();i++){
            t_mul*=(nums[i])*1LL;
        }
        __int128 tar=(__int128)target*target;
        return t_mul==tar;
    }
};