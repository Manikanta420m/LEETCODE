class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long l=*min_element(ranks.begin(),ranks.end());
        long long r=l*cars*cars;
        long long ans=r;
        while(l<=r){
            long long mid=l+(r-l)/2;
            long long ansi=0;
            for(int i=0;i<ranks.size();i++){
                ansi+=sqrt(mid/ranks[i]);
            }
            if(ansi>=cars){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }return ans;
    }
};