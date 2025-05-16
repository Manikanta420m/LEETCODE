vector<int> adj[1000];
class Solution {
public:
    static bool hamming1(string& s, string& t){
        const int sz=s.size();
        if (sz!=t.size()) return 0;
        int diff=0;
        for (int i=0; i<sz && diff<2; i++)
            diff+=s[i]!= t[i];
        return diff==1;
    }
    static vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        const int n=words.size();
        vector<int> deg(n, 0), prev(n, -1);

        //Kahn's algo
        for (int i=0; i<n; i++) {//Build adjacent list
            adj[i].clear();
            for (int j=0; j<i; j++) {
                if (groups[i]!=groups[j] && hamming1(words[i], words[j])) {
                    adj[i].push_back(j);// directed edge (j, i)
                    deg[j]++;// indegree 
                }
            }
        }
        // BFS
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (deg[i]==0) q.push(i);
        }

        int iMax= 0;
        while (!q.empty()) {
            int x=q.front();
            q.pop();
            for (int y : adj[x]) {
                if (--deg[y] == 0) {
                    q.push(y);
                    prev[y]=x;//assign prev
                }
            }
            iMax=x;
        }
        vector<string> ans;
        for (int j=iMax; j!=-1; j=prev[j]) {
            ans.push_back(words[j]);
        }
        return ans;
    }
};