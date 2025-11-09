#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>pre(n,0);
        for(int i=0;i<n;i++){
            if(nums[i]==target)pre[i]=1;
            else pre[i]=-1;
            if(i)pre[i]+=pre[i-1];
        }
        ordered_set<pair<int,int>>st;
        st.insert({0,0});
        long long ans=0;
        for(int i=0;i<n;i++){
            ans+=st.order_of_key({pre[i],-1});
            st.insert({pre[i],i});
        }
        return ans;
    }
};