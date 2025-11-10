class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        vector<int>nse(n,n);
        map<int,set<int>>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]].insert(i);
        }
        stack<int>st;
        st.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(!st.empty() and nums[i]<=nums[st.top()]){
               st.pop();
            }
            if(st.size()>0){
                nse[i]=st.top();
            }
            st.push(i);
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0)continue;
            int j=nse[i];
            for(auto x:mp[nums[i]]){
                if(x>=j)break;
                mp[nums[i]].erase(x);
                nums[x]=0;
            }
            cnt++;
        }
        return cnt;
    }
};