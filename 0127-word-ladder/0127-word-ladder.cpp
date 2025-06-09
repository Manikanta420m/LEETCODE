class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        unordered_set<string>st(wordList.begin(),wordList.end());
        st.erase(beginWord);
        while(!q.empty()){
            string s1=q.front().first;
            int steps=q.front().second;
            q.pop();
            if(s1==endWord)return steps;
            for(int i=0;i<s1.size();i++){
                char org=s1[i];
                for(char ch='a';ch<='z';ch++){
                    s1[i]=ch;
                    if(st.find(s1)!=st.end()){
                        st.erase(s1);
                        q.push({s1,steps+1});
                    }
                }
                s1[i]=org;
            }
        }return 0;
    }
};