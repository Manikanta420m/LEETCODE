class Solution {
public:
    bool checkValidString(string s) {
        int maxi=0,mini=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            
            if(s[i]=='('){
                maxi++;
                mini++;

            }
            else if(s[i]==')'){
                maxi--,mini=max(mini-1,0);
            }
            else if(s[i]=='*'){
                maxi++;
                mini=max(mini-1,0);
            }
            if(maxi<0){
                return false;
            }
        }
        return mini==0;
    }
};