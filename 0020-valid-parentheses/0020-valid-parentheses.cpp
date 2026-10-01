class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(auto i:s){
            if(i=='(' or i=='{' or i=='[')st.push(i);
            else {
                if(i==')'){
                    if(!st.empty() and st.top()=='(')st.pop();
                    else return false;
                }
                else if(i=='}'){
                    if(!st.empty() and st.top()=='{')st.pop();
                    else return false;
                }
                else{
                    if(!st.empty() and st.top()=='[')st.pop();
                    else return false;
                }
            }
        }
        return st.empty()?true:false;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna