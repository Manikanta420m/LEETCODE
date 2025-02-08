class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if((long)m*k>n)return -1;
        int mini=*min_element(bloomDay.begin(),bloomDay.end());
        int maxi=*max_element(bloomDay.begin(),bloomDay.end());
        int l=mini,r=maxi;
        int ansi=r;
        while(l<r){
            int mid=l+(r-l)/2;
            int c=0,ans=0;
            for(int i=0;i<n;i++){
               if(bloomDay[i]<=mid)c++;
               else c=0;
               if(c==k){ans++;c=0;}
            }
            if(ans>=m){
              ansi=mid;
              r=mid;
            }
            else l=mid+1;
        }return ansi;
    }
};