class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n=colors.size();
        int ans=0,maxi=1;
        for(int i=1;i<n+k-1;i++){
            if(colors[i%n]!=colors[(i-1+n)%n])maxi++;
            else maxi=1;
            if(maxi>=k)ans++;
        }return ans;
    }
};