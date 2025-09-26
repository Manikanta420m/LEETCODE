class Solution {
public:
    int triangleNumber(vector<int>& a) {
        sort(a.begin(),a.end());
        int ans=0;
        for(int i=a.size()-1;i>=2;i--){
           int l=0,r=i-1;
           while(l<r){
            if(a[l]+a[r]>a[i]){
                ans+=(r-l);
                r--;
            }
            else l++;
           }
        }
        return ans;
    }
};