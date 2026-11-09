class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        vector<int>count(k,0);
        set<int> s;
        for(int i=0;i<k;i++)
        s.insert(i);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<arrival.size();i++){
            int server=i%k;
            while(!pq.empty() && pq.top().first<=arrival[i]){
                int freeServer=pq.top().second;
                s.insert(freeServer);
                pq.pop();
            }
            if(s.empty())
                continue;
            else {
                auto it=s.lower_bound(server);
                if(it==s.end())
                it=s.lower_bound(0);
                pq.push({arrival[i]+load[i],*it});
                count[*it]++;
                s.erase(*it);
            }
        }
        int maxVal=0;
        for(int i=0;i<count.size();i++)
            maxVal=max(maxVal,count[i]);

        vector<int>sol;
        for(int i=0;i<count.size();i++){
            if(count[i]==maxVal)
            sol.push_back(i);
        }
        return sol;
    }
};