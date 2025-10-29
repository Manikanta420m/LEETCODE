class Solution {
public:
    int smallestNumber(int n) {
        int b=floor(log2(n))+1;
        return (1<<b)-1;
    }
};