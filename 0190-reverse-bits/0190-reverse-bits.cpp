class Solution {
public:
    int reverseBits(int n) {
        bitset<32> B(n);
        for(int i=0; i<16; i++){
            B[i]=B[i]^B[31-i];
            B[31-i]=B[i]^B[31-i];
            B[i]=B[i]^B[31-i];
        }     
        return B.to_ulong();

    }
};