class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long long psum=0,odd=0;
        for(int i:arr){
            psum+=i;
            odd+=psum%2;
        }
        odd+=(arr.size()-odd)*odd;
        return odd%1'000'000'007;
    }
};