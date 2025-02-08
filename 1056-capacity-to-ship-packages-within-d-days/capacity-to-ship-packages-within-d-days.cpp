class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
       int mini=*max_element(weights.begin(),weights.end()),n=weights.size();
       int maxi=accumulate(weights.begin(),weights.end(),0);
       int l=mini,r=maxi,ansi=maxi;
       while(l<r){
         int mid=l+(r-l)/2;
         int c=0,ans=0;
         for(int i=0;i<n;i++){
           if(ans+weights[i]>mid){
            ans=weights[i];
            c++;
           }
           else ans+=weights[i];
         }
         if(ans>0)c++;
         if(c<=days){
            ansi=mid;
            r=mid;
         }
         else l=mid+1;
       }return ansi;
    }
};