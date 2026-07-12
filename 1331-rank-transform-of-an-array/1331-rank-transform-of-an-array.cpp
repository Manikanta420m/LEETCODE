class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
      set<int>st(arr.begin(),arr.end());

      unordered_map<int,int>mp;

      int cnt=1;

      for(auto i:st){
        mp[i]=cnt++;
      }

      for(auto &i:arr)i=mp[i];
      return arr;

    }
};
 
