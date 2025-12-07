class Solution {
public:
    vector<int>res;
    
    bool isPalindrome(string s){
        int i=0,j=s.size()-1;
        while(i<=j){
            if(s[i++]!=s[j--])return false;
        }
        return true;
    }
    
    void solve(){
        for(int i=0;i<=10000;i++){
           string s;
           int n=i;
           while(n>0){
             s.push_back((n & 1) ? '1' : '0');
             n >>= 1;
           }
           reverse(s.begin(),s.end());
         if(isPalindrome(s))res.push_back(i);
        }
    }
    
    vector<int> minOperations(vector<int>& nums) {
        solve();
        vector<int>ans;
        // for(int i=0;i<nums.size();i++){
        //     int low=*lower_bound(res.begin(),res.end(),nums[i]);
        //     int high=*upper_bound(res.begin(),res.end(),nums[i]);
        //     ans.push_back(min(abs(nums[i]-low),abs(nums[i]-high)));
        // }
        for (int x : nums) {
            auto it = lower_bound(res.begin(), res.end(), x);

            int best = INT_MAX;

            if (it != res.end())
                best = min(best, abs(*it - x));

            if (it != res.begin()) {
                it--;
                best = min(best, abs(*it - x));
            }

            ans.push_back(best);
        }
        return ans;
    }
};