class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int ans=0,prev=-1,maxi=0;
        vector<int>suf(events.size(),0);
        int suf_max=-1;
        sort(events.begin(),events.end());
        for(int i=events.size()-1;i>=0;i--){
            suf_max=max(suf_max,events[i][2]);
            suf[i]=suf_max;
        }
        for(int i=0;i<events.size();i++){
           ans=max(ans,events[i][2]);
           int l=i+1,r=events.size()-1;
           while(l<=r){
            int mid=l+(r-l)/2;
            if(events[mid][0]>events[i][1])r=mid-1;
            else l=mid+1;
           }
           int idx=l;
           if(idx<events.size())ans=max(ans,events[i][2]+suf[idx]);
        }
        return ans;
    }
};