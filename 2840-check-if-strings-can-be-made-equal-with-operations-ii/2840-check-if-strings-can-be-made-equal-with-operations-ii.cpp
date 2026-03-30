class Solution {
public:
    bool checkStrings(string s1, string s2) {
        unordered_map<char,int>mp1,mp2;
        for(int i=0;i<s1.size();i++){
            if(i&1)mp1[s1[i]]++;
            else mp2[s1[i]]++;
        }
        for(int i=0;i<s2.size();i++){
            if(i&1){
               if(mp1.find(s2[i])==mp1.end())return false;
               else{
                  mp1[s2[i]]--;
                  if(mp1[s2[i]]==0)mp1.erase(s2[i]);
               } 
            }
            else{
               if(mp2.find(s2[i])==mp2.end())return false;
               else{
                  mp2[s2[i]]--;
                  if(mp2[s2[i]]==0)mp2.erase(s2[i]);
               }             
            }
        }
        return true;
    }
};