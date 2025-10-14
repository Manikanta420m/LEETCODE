class Solution {
public:
bool f(int i,int k,vector<int>& a){
    for(int x=i;x<i+k-1;x++){
        if(a[x]>=a[x+1])return false;
    }return true;
}
    bool hasIncreasingSubarrays(vector<int>& a, int k) {
        int n=a.size();
            for(int i=0;i<=n-2*k;i++){
                if(f(i,k,a)&&f(i+k,k,a))return true;
            }
        return false;
    }
};