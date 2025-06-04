class Solution {
public:
    string answerString(string word, int numFriends) {
        int n=word.size();
        int req=n-(numFriends)+1;
        if(numFriends==1)return word;
        vector<string>res;
        for(int i=0;i<n;i++){
           string s=word.substr(i,min(req,n-i));
           res.push_back(s);
        }
        sort(res.rbegin(),res.rend());
        return res[0];
    }
};