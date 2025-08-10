class Solution {
public:
    long long maxTotal(vector<int>& value, vector<int>& limit) {
        long long ans=0;
        int n=value.size();
        unordered_map<int,priority_queue<int>>mp;
        for(auto i=0;i<n;i++)mp[limit[i]].push(value[i]);
        for(auto i:mp){
            int maxi=i.first;
            auto pq=i.second;
            while(!pq.empty() and maxi){
                ans+=pq.top();
                pq.pop();
                maxi--;
            }
        }
        return ans;
    }
};