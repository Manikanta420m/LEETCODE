class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int ans=0,n=fruits.size();
        for(int i=0;i<n;i++){
            bool vis=false;
            for(int j=0;j<n;j++){
                if(baskets[j]>=fruits[i]){
                    baskets[j]=-1;
                    vis=true;
                    break;
                }
            }
            if(vis)ans++;
        }return n-ans;
    }
};