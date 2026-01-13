class Solution {
private:
    // return true if area below y = mid >= tar
    static bool check(double mid, const vector<vector<int>>& squares, double tar) {
        double sm = 0.0;
        for (const auto &s : squares) {
            double y = s[1];
            if (mid <= y) continue;                    // no contribution
            double len = s[2];
            double h = mid - y;
            if (h >= len) sm += len * len;            // full square
            else sm += len * h;                       // partial height * width
            if (sm >= tar) return true;               // early exit
        }
        return sm >= tar;
    }

public:
    double separateSquares(vector<vector<int>>& squares) {
        // compute total area and search bounds
        double tot = 0.0;
        double minY = numeric_limits<double>::infinity();
        double maxTop = -numeric_limits<double>::infinity();

        for (const auto &s : squares) {
            double y = s[1];
            double len = s[2];
            tot += len * len;
            if (y < minY) minY = y;
            double top = y + len;
            if (top > maxTop) maxTop = top;
        }

        double tar = tot * 0.5;
        double l = minY, r = maxTop;
        const double eps = 1e-7;     // precision for 1e-5 answers
        int iter = 0, maxIter = 80;  // safety cap

        while (r - l > eps && iter++ < maxIter) {
            double mid = (l + r) * 0.5;
            if (check(mid, squares, tar)) r = mid;
            else l = mid;
        }

        return r; // minimal y such that areaBelow(y) >= tar
    }
};
