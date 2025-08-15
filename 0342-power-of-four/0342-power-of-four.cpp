class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n < 1)
            return false;
        int bits = __popcount(n);
        int noOfBits = log2(n)+1;
        return bits == 1 and (noOfBits - bits) % 2 == 0;
    }
};