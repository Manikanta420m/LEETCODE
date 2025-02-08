class Solution {
public:
    int findKthPositive(vector<int>& a, int k) {
       int l=0,h=a.size();
       while(l<h){
        int mid=l+(h-l)/2;
        if(a[mid]-mid>k)h=mid;
        else l=mid+1;
       }return l+k;
    }
};