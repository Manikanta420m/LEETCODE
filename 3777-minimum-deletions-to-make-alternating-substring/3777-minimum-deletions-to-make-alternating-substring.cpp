class Solution {
public:
    long long bit[100001],n;
    
    void update(int i,int x){
       for(++i;i<=n;i=i+(i&(-i))){
        bit[i]+=x;
       }
    }

    int query(int i){
        int ans=0;
       for(++i;i>0;i=i-(i&(-i))){
        ans+=bit[i];
       }
       return ans;
    }

    vector<int> minDeletions(string s, vector<vector<int>>& queries) {
         n=s.size();
        memset(bit,0,sizeof(bit));
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                update(i,1);
            }
        }
        vector<int>ans;
        for(auto q:queries){
            if(q[0]==1){
                int j=q[1];
                if(j-1>=0 and s[j]==s[j-1])update(j-1,-1);
                if(j+1<n and s[j]==s[j+1])update(j,-1);
                s[j]=(s[j]=='A'?'B':'A');
                if(j-1>=0 and s[j]==s[j-1])update(j-1,1);
                if(j+1<n and s[j]==s[j+1])update(j,1);
            }
            else{
                int l=q[1],r=q[2];
                int res=query(r-1)-(l?query(l-1):0);
                ans.push_back(res);
            }
        }
        return ans;
    }
};