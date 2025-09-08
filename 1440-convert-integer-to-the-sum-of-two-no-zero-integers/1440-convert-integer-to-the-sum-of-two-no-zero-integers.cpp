class Solution {
private:
    bool check(int n){
        while(n>0){
            if(n%10==0)return false;
            n/=10;
        }
        return true;
    }
public:
    vector<int> getNoZeroIntegers(int n) {
        for(int i=1;i<n;i++){
            if(check(i) and check(n-i)) return {i,n-i};
        }
        return {-1,-1};
    }
};