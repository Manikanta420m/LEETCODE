class Solution {
public:

    char check(vector<int>&frq){
        for(int i=0;i<26;i++){
            if(frq[i])return i+'a';
        }return 'a';
    }

    string robotWithString(string s) {
        stack<int>st;
        string t="";
        vector<int>frq(26);
        for(char ch:s){
            frq[ch-'a']++;
        }
        for(char ch:s){
            st.push(ch);
            frq[ch-'a']--;
            while(!st.empty() and st.top()<=check(frq)){
                t+=st.top();
                st.pop();
            }
        }
        while(!st.empty()){
            t+=st.top();
            st.pop();
        }
        return t;
    }
};