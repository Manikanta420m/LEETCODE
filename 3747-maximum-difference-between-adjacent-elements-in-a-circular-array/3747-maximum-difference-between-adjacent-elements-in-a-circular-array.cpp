class Solution {
public:
    int maxAdjacentDistance(vector<int>& a) {
     int maxi=0;
     for(int i=1;i<a.size();i++){
        maxi=max(maxi,abs(a[i]-a[i-1]));
        if(i==a.size()-1) maxi=max(maxi,abs(a[i]-a[0]));
     }  return maxi;
    }
};