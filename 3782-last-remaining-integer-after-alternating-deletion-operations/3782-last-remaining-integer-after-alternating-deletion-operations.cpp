class Solution {
public:
    long long lastInteger(long long n) {
        long long step=1,head=1,siz=n;
        bool left=false;
        while(siz>1LL){
           if(left and !(siz&1)){
            head+=step;
           }
           step*=2LL;
           left=!left;
           siz=(siz+1LL)/2LL;
        }
        return head; 
    }
};