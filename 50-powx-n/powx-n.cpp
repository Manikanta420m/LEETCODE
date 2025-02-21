class Solution {
public:
    //  double fun(double x, int n){
    //     if(n==1)return 1;
    //     double temp=fun(x,n/2);
    //     if(n&1)return temp*temp*x;
    //     return temp*temp;
    //  }

    double myPow(double x, int n) {
     if(n==0)return 1;
     if(n<0)return (double)1.0/x*myPow((double)1.0/x,-(++n));
     if(n%2==1)return x*myPow(x*x,n/2);
     else return myPow(x*x,n/2); 
   }
};