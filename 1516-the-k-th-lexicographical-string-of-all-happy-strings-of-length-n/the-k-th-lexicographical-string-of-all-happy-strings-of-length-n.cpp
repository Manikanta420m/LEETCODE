class Solution {
public:
    string getHappyString(int n, int k) {
        vector<string>ans;
        queue<string>q;
        q.push("a");
        q.push("b");
        q.push("c");
        while(!q.empty()){
            string cur=q.front();
            q.pop();
            if(cur.size()==n){
                ans.push_back(cur);
                continue;
            }
            string fir=cur;
            string sec=cur;
            if(cur.back()=='a'){
                fir.push_back('b');
                sec.push_back('c');
            }
            else  if(cur.back()=='b'){
                fir.push_back('a');
                sec.push_back('c');
            }
            else  if(cur.back()=='c'){
                fir.push_back('a');
                sec.push_back('b');
            }
            q.push(fir);
            q.push(sec);
        }
        return ans.size()>=k?ans[k-1]:"";
    }
};