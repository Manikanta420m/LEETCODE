class Solution {
public:
    static const int MAXN = 50;
    long long nCr[MAXN + 1][MAXN + 1];

    void precompute_nCr() {
        for (int n = 0; n <= MAXN; n++) {
            nCr[n][0] = nCr[n][n] = 1;
            for (int r = 1; r < n; r++) {
                nCr[n][r] = nCr[n - 1][r - 1] + nCr[n - 1][r];
            }
        }
    }
    long long nthSmallest(long long n, int k) {

        precompute_nCr();

        long long mini = 1e18;

        for (int i = k; i <= 50; i++) {
            if (n > nCr[i][k]) {
                continue;
            }
            long long ans = 0;
            long long val = n;
            int bits = 0;

            for (int j = i; j >= 2; j--) {
                long long rem = nCr[j - 1][k-bits];
               
                if (val - rem >= 1) {
                  
                    val -= rem;
                    bits++;
                 
                    ans = ans | (1LL << (j - 1));
                  
                } 
            }
            for (int j = 0; j < k - bits; j++) {
                ans = ans | (1LL << j);
            }
             
             return ans;
        }

        return mini;
    }
};