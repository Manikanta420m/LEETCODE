class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int k) {
        int n=piles.size();
        int l=1,h=*max_element(piles.begin(),piles.end());
        int ans=h;
        while(l<h){
            int mid=l+(h-l)/2;
            int c=0;
            for(int i=0;i<n;i++){
                c+=(mid+piles[i]-1)/mid;
            }
            if(c<=k){
                ans=mid;
               h=mid; 
            }
            else l=mid+1;
        }return ans;
    }
};