class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int>ans;
        int x=1;
        for(int i=digits.size()-1;i>=0;i--){
            digits[i]+=x;
            x=digits[i]/10;
            digits[i]%=10;
            ans.push_back(digits[i]);
        }
        if(x!=0)ans.push_back(x); 
        reverse(ans.begin(),ans.end());
        return ans;
    }
};