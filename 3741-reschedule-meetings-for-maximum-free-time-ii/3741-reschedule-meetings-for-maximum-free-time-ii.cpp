class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        vector<int>space;
        space.push_back(startTime[0]-0);
        int n=startTime.size();
        for(int i=1;i<n;i++)space.push_back(startTime[i]-endTime[i-1]);
        space.push_back(eventTime-endTime[n-1]);
        vector<int>right(space.size(),0);
        for(int i=space.size()-2;i>=0;i--)right[i]=max(right[i+1],space[i+1]);
        int ans=0,left=0;
        for(int i=1;i<space.size();i++){
            int cur=endTime[i-1]-startTime[i-1];
            if(cur<=max(left,right[i]))ans=max(ans,space[i-1]+space[i]+cur);
            ans=max(ans,space[i-1]+space[i]);
            left=max(left,space[i-1]);
        }
        return ans;
    }
};