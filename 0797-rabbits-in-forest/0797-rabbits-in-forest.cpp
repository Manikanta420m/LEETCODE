class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int>mp;
        for(int i=0;i<answers.size();i++){
            mp[answers[i]]++;
        }
        int ans=0;
        for(auto i:mp){
            int siz=i.first+1;
            int grps=(i.first+i.second)/siz;
            ans+=grps*siz;
        }
        return ans;
    }
};