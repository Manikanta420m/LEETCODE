class Solution {
public:
    int lastRemaining(int n) {
        int step=1,head=1,siz=n;
        bool left=true;
        while(siz>1){
           if(left or siz&1){
            head+=step;
           }
           step*=2;
           left=!left;
           siz/=2;
        }
        return head;
    }
};