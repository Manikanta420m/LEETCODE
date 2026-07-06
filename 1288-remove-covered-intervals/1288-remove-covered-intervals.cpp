class Solution {
public:
    static bool comp(const vector<int>&p1,vector<int>&p2){
        if(p1[0]==p2[0])return p1[1]>p2[1];
        return p1[0]<p2[0];
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end(),comp);
        int maxi=0,ans=0;
        for(auto i:intervals){
            if(i[1]>maxi){
                maxi=i[1];
                ans++;
            }
        }
        return ans;
    }
};