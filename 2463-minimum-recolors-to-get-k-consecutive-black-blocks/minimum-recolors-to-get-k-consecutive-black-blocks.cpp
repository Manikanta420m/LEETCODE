class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n=blocks.size();
        int c=0;
        vector<int>pre(n);
        for(int i=0;i<n;i++){
            if(blocks[i]=='B')c++;
            pre[i]=c;
        }
        if(n<k)return 0;
        int maxi=pre[k-1];
        for(int i=k;i<n;i++){
            maxi=max(maxi,pre[i]-pre[i-k]);
        }
        return maxi>=k?0:k-maxi;
    }
};