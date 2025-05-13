class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
       vector<int>frq(26,0);
       const int M=1e9+7;
       for(auto i:s)frq[i-'a']++;
       while(t--){
          vector<int>temp(26,0);
          for(int i=0;i<26;i++){
            if(i==25){
                temp[0]=(temp[0]+frq[i])%M;
                temp[1]=(temp[1]+frq[i])%M;
            }
            else temp[i+1]=(temp[i+1]+frq[i])%M;
          }frq=temp;
       }
       int ans=0;
       for(auto i:frq)ans=(ans+i)%M;
       return ans;
    }
};