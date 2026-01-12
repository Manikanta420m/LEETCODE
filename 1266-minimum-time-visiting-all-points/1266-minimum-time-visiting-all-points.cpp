class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans=0;
        int px=points[0][0],py=points[0][1];
        for(auto i:points){
            int x=i[0],y=i[1];
            ans+=max(abs(px-x),abs(py-y));
            px=x;
            py=y;
        }
        return ans;
    }
};