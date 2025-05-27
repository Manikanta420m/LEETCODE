class Solution {
public:
    int differenceOfSums(int n, int m) {
      int s=n*(n+1)/2;
      int div=n/m;
      return s-(div*(div+1)*m);  
    }
};