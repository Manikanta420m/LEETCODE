class Solution {
public:
    long long minNumberOfSeconds(int height, vector<int>& times) {

        long long lo = 1;
        long long hi = 10000000000000000LL;

        while (lo < hi) {

            long long mid = (lo + hi) >> 1;
            long long totalLayers = 0;

            for (int t : times) {

                if (totalLayers >= height)
                    break;

                long long layers = (long long)(sqrt((2.0 * mid) / t + 0.25) - 0.5);

                totalLayers += layers;
            }

            if (totalLayers >= height)
                hi = mid;
            else
                lo = mid + 1;
        }

        return lo;
    }
};