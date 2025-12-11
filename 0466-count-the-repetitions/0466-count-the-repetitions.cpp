class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        int idx=0,ans=0;
        int l1=s1.size(),l2=s2.size();
        for(int i=0;i<n1;i++){
            for(int j=0;j<l1;j++){
                if(s1[j]==s2[idx])idx++;
                if(idx==l2){
                    idx=0;
                    ans++;
                }
            }
        }
        return ans/n2;
    }
};