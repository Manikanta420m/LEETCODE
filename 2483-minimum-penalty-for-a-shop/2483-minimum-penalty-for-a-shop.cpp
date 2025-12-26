class Solution {
public:
    int bestClosingTime(string customers) {
        int n=customers.size();
        int p=0;
        int minp=0,mini=0;
        for(int i=0;i<n;i++){
            int y=customers[i]=='Y'?1:-1;
            p-=y;
            if(minp>p){
              minp=p;
              mini=i+1;
            }
        }
        return mini;
    }
};