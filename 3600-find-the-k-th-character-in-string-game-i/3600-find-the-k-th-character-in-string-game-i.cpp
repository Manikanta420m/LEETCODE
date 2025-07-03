class Solution {
public:
    char kthCharacter(int k) {
    string s;
        s="a";
        while(k>s.length()){
            string s1="";
            for(char ch:s){
                if(ch=='z') s1+='a';
                else s1+=ch+1;
            }
            s+=s1;
        }
        return s[k-1];
    }
};