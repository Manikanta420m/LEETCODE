class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m=languages.size();
        vector<bool> done(m+1,true);

        vector<bitset<501>> lang(m+1,0);
        for(int i=1;i<=m;i++){
            for(auto &j : languages[i-1]){
                lang[i].set(j);
            }
        }
        for(auto &i : friendships){
            if((lang[i[0]] & lang[i[1]])==0){
                done[i[0]]=false;
                done[i[1]]=false;
            }
        }
        int ans=INT_MAX;
        for(int i=1;i<=n;i++){
            int curr=0;
            for(int j=1;j<=m;j++){
                if((!done[j]) && (lang[j][i]==0)) 
                    curr++;
            }
            ans=min(curr,ans);
            
        }
        return ans;
    }
};