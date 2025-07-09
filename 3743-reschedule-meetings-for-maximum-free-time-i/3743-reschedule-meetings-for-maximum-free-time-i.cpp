class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<int>spaces;
        spaces.push_back(startTime[0]-0);
        int n=startTime.size();
        for(int i=1;i<n;i++)spaces.push_back(startTime[i]-endTime[i-1]);
        spaces.push_back(eventTime-endTime[n-1]);
        int ans=INT_MIN;
        int res=0;
        for(int i=0;i<spaces.size();i++){
            if(i<=k)res+=spaces[i];
            else {
                res-=spaces[i-k-1];
                res+=spaces[i];
            }
            ans=max(ans,res);
        }
        return ans;
    }
};