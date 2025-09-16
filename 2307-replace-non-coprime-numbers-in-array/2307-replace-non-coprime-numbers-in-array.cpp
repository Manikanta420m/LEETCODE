class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<int>st;
        for(int i=0;i<nums.size();i++){
            st.push(nums[i]);
            while(st.size()>1){
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                if(__gcd(a,b)==1){st.push(b);st.push(a);break;}
                else {
                    st.push((int)(lcm(a,b)));
                }
            }  
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};