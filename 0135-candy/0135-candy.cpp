class Solution {
public:
    int candy(vector<int>& ratings) {
        int ans=0;
        int n=ratings.size();
        vector<int>psum(n),ssum(n);
        psum[0]=1;ssum[n-1]=1;
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1])psum[i]=psum[i-1]+1;
            else psum[i]=1;
        }
        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1])ssum[i]=ssum[i+1]+1;
            else ssum[i]=1;
        }
        for(int i=0;i<n;i++)ans+=max(psum[i],ssum[i]);
        return ans;
    }
};