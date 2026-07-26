class Solution {
public:
    int largestInteger(int n, int s) {
        if(9*n<s)return -1;
        int num=0;
        while(n){
            num=num*10+(min(9,s));
            s-=min(9,s);
            n--;
        }
        return num;
    }
};