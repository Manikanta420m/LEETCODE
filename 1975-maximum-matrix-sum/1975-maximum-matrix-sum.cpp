class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long ans=0;
        int mini=INT_MAX,neg=0;
        bool z=false;
        for(auto i:matrix){
            for(auto j:i){
                mini=min(mini,abs(j));
                ans+=abs(j);;
                if(j<0)neg++;
                if(j==0)z=true;
            }
        }
        if(z or !(neg&1))return ans;
        return ans-2*mini;
    }
};