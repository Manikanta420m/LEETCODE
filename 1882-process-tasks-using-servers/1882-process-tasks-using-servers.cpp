class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > freeServers;
        priority_queue<
            tuple<long long, int, int>,
            vector<tuple<long long, int, int>>,
            greater<tuple<long long, int, int>>
        > busyServers;

        for (int i = 0; i < n; i++) {
            freeServers.push({servers[i], i});
        }

        vector<int> result(m);

        for (int i = 0; i < m; i++) {
            while (!busyServers.empty() &&
                   get<0>(busyServers.top()) <= i) {

                auto [finishTime, weight, index] = busyServers.top();
                busyServers.pop();

                freeServers.push({weight, index});
            }

            long long startTime;
            int weight, index;

            if (freeServers.empty()) {
                auto cur = busyServers.top();
                busyServers.pop();

                startTime = get<0>(cur);
                weight = get<1>(cur);
                index = get<2>(cur);

            } else {
                auto cur = freeServers.top();
                freeServers.pop();

                startTime = i;
                weight = cur.first;
                index = cur.second;
            }

            result[i] = index;

            busyServers.push({
                startTime + tasks[i],
                weight,
                index
            });
        }

        return result;
    }
};