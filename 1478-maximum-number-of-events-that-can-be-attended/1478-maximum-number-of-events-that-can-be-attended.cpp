class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        int time=1;
        int pos=0,attended=0;
        int n=events.size();
        priority_queue<int,vector<int>,greater<int>>minheap;
        while(pos<n or !minheap.empty()){
            if(minheap.empty()){
                time=max(time,events[pos][0]);
            }
            while(pos<n and events[pos][0]==time){
                minheap.push(events[pos][1]);
                pos++;
            }
            while(!minheap.empty() and minheap.top()<time){
                minheap.pop();
            }
            if(!minheap.empty()){
                minheap.pop();
                attended++;
            }
            time++;
        }
        return attended;
    }
};