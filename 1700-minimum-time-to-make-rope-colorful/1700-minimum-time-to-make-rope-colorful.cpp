class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans=0;
        int maxi=neededTime[0];
        for(int i=1;i<colors.size();i++){
            if(colors[i]==colors[i-1]){
               if(maxi<neededTime[i]){
                ans+=maxi;
                maxi=neededTime[i];
               }
               else{
                ans+=neededTime[i];
               }
            }
            else{
                maxi=neededTime[i];
            }
        }
        return ans;
    }
};