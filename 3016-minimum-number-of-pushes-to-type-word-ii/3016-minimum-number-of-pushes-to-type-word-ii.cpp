class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size(),ans=0,c=1;
        unordered_map<char,int>mp;
        for(auto i:word){
            mp[i]++;
        }
        vector<int>v;
        for(auto i:mp){
            v.push_back(i.second);
        }
        sort(v.rbegin(),v.rend());
        int m=v.size();
        for(int i=0;i<m;i++){
            if(i<8)ans+=v[i];
            else if(i>=8 and i<16)ans+=(2*v[i]);
            else if(i>=16 and i<24)ans+=(3*v[i]);
            else ans+=(4*v[i]);
        }
        return ans;
    }
};