class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string s(num, '0');
        auto [q, r]=div(sum, 9);
        if (q+(r>0)>num) return "";
        fill(s.begin(), s.begin()+q, '9');
        s[q]='0'+r;
        return s;
    }
};