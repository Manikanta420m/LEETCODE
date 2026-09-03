class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        bool allEven=true,allOdd=true;
        int mini=INT_MAX;
        for(auto i:nums1){
            if(i&1)allEven=false;
            else allOdd=false;
            mini=min(mini,i);
        }
        if(mini&1 or (allEven or allOdd))return true;
        return false;
    }
};