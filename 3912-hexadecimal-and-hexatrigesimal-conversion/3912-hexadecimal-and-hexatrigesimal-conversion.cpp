class Solution {
public:
    string concatHex36(int n) {
        long long n2 = 1LL * n * n;
        long long n3 = 1LL * n * n * n;

        // Convert to hexadecimal (uppercase)
        string hex_part;
        string hexa="0123456789ABCDEF";
        while(n2>0){
            hex_part=hexa[n2%16]+hex_part;
            n2/=16;
        }
        // Convert to base-36 (uppercase)
        string base36_chars = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string base36_part;

        while (n3 > 0) {
            base36_part = base36_chars[n3 % 36] + base36_part;
            n3 /= 36;
        }

        return hex_part + base36_part;
    }
};