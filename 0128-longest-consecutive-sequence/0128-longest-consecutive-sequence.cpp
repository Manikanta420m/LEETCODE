class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       int n=nums.size();
       if(n==0)return 0;
       int l=0;
       unordered_set<int>st;
       for(auto i:nums)st.insert(i);
       for(auto i:st){
           if(st.find(i-1)==st.end()){
            int c=1;
            int idx=i;
            while(st.find(idx+1)!=st.end()){
                c++;
                idx+=1;
            }l=max(l,c);
           }
       } return l;
    }
};