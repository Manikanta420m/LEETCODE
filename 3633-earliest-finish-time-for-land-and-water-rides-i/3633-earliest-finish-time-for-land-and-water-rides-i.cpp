class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n=landStartTime.size(),m=waterStartTime.size(),ans=INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int res=landStartTime[i]+landDuration[i];
                if(res<waterStartTime[j])res+=(waterStartTime[j]-res);;
                res+=waterDuration[j];
                ans=min(ans,res);
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int res=waterStartTime[i]+waterDuration[i];
                if(res<landStartTime[j])res+=(landStartTime[j]-res);;
                res+=landDuration[j];
                ans=min(ans,res);
            }
        }
        return ans;
    }
};