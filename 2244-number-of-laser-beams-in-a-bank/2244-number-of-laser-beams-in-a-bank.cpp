class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans=0,prev=0;
        for(int i=0;i<bank.size();i++){
              int cnt=count(bank[i].begin(),bank[i].end(),'1');
              if(i!=0)ans+=(prev*cnt);
              if(cnt!=0)prev=cnt;
        }
        return ans;
    }
};