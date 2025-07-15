class Solution {
public:
    bool isValid(string s) {
        bool v=false,ct=false;
        int n=s.size();
        if(n<3)return false;
        for(int i=0;i<n;i++){
            if(s[i]=='a' or s[i]=='e' or s[i]=='i' or s[i]=='o' or s[i]=='u'
            or s[i]=='A' or s[i]=='E' or s[i]=='I' or s[i]=='O' or s[i]=='U')
              v=true;
            else if((s[i]>='a' and s[i]<='z') or (s[i]>='A' and s[i]<='Z'))ct=true;
            if((s[i]>='0' and s[i]<='9') 
            or (s[i]>='a' and s[i]<='z')
            or (s[i]>='A' and s[i]<='Z')) continue;
            else return false;
        }
        return v and ct;
    }
};