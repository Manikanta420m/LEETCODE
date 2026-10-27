class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string>ans;
        if(m==1 and n==1){
            ans.push_back(".");
            return ans;
        }
        
        string s;
        for(int i=0;i<n;i++){
            s+='.';
        }
        ans.push_back(s);
        s.clear();
        for(int i=0;i<m-1;i++){
            string s1;
            for(int i=0;i<n-1;i++){
            s1+='#';
            }s1+='.';
            ans.push_back(s1);
        }
        return ans;
    }
};