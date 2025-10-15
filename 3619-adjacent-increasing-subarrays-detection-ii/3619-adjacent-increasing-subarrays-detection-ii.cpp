class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& a) {
        int n=a.size();
        vector<int>ans;
        int c=1;
        for(int i=0;i<n-1;i++){
            if(a[i]<a[i+1])c++;
            else{
                ans.push_back(c);
                c=1;
            }
        }ans.push_back(c);
        if(ans.size()==1){
            int maxi=ans[0]/2;
            return maxi;
        }
        int res=0,maxi=0,maxa=0;
        for(int i=0;i<ans.size()-1;i++){
            res=min(ans[i],ans[i+1]);
            maxi=max(res,maxi);
            maxa=max(maxa,ans[i]);
        }
        maxa=max(maxa,ans[ans.size()-1]);
        maxi=max(maxa/2,maxi);
        return maxi;
    }
};