class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
      for(int i=2;i<arr.size();i++){
        if(arr[i]&1 and arr[i-1]&1 and arr[i-2]&1)return true;
      }
      return false;  
    }
};