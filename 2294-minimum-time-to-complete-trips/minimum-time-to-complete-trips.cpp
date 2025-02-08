class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long mini=*min_element(time.begin(),time.end());
        long long maxi=*max_element(time.begin(),time.end());
        long long l=1,r=1e14;
        long long n=time.size(),ans=1e14;
        while(l<=r){
            long long mid=l+(r-l)/2;
            long long c=0;
            for(int i=0;i<n;i++){
                c+=((mid)/time[i]);
            }
            if(c>=totalTrips){
                ans=min(ans,mid);
                r=mid-1;
            }
            else {
                l=mid+1;
             
            }
        }return ans;
    }
};