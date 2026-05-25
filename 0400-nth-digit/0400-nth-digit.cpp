class Solution {
public:
    int findNthDigit(int n) {
        long long digi=9;
        int fir=1;
        int len=1;
        while(n>digi*len){
            n-=digi*len;
            fir*=10;
            digi*=10;
            len++;
        }
        fir=fir+(n-1)/len;
        string s=to_string(fir);
        return s[(n-1)%len]-'0';
    }
};