class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char,int>mp;
        for(auto &i:word)mp[i]++;
        vector<int>frq;
        for(auto i:mp)frq.push_back(i.second);
        sort(frq.begin(),frq.end());
        int n=frq.size();
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            int bse=frq[i];
            int del=0;

            for(int j=0;j<i;j++){
                del+=frq[j];
            }

            for(int j=i+1;j<n;j++){
                if(frq[j]>bse+k){
                    del+=frq[j]-(bse+k);
                }
            }
            ans=min(ans,del);
        }return ans;
    }
};