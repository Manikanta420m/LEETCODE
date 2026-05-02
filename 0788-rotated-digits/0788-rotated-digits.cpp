class Solution {
    bool isValid(int num) {
        bool res = false;
        while(num != 0) {
            int digit = num % 10; num /= 10;
            if(digit == 2 || digit == 5 || digit == 6 || digit == 9) res = true;
            else if(digit == 3 || digit == 4 || digit == 7) return false;
        }
        return res;
    }

public:
    int rotatedDigits(int n) {
        int cnt = 0;
        for(int num = 1; num <= n; num++) {
            if(isValid(num)) cnt++;
        }
        return cnt;
    }
};