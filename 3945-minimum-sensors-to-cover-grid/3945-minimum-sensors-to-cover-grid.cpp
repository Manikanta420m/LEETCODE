class Solution {
public:
    int minSensors(int n, int m, int k) {
        int reg=k*2+1;
        return ((m+reg-1)/reg)*((n+reg-1)/reg);
    }
};