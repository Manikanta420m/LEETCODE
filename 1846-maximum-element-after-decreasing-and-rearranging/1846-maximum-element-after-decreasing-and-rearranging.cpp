class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n=arr.size();
        int res=0;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            if(res<arr[i])res++;
        }
        return res;
    }
};