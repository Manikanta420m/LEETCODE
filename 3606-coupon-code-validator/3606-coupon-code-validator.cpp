class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<pair<string,string>>ans;
        int n=code.size();
        for(int i=0;i<n;i++){
            bool f=true;
            if(code[i]=="")f=false;
            for(int j=0;j<code[i].size();j++){
                if((code[i][j]>='a' and code[i][j]<='z') or 
                   (code[i][j]>='A' and code[i][j]<='Z') or 
                   (code[i][j]>='0' and code[i][j]<='9') or 
                   code[i][j]=='_'
                )continue;
                else f=false;
            }
            if(businessLine[i]=="electronics" or businessLine[i]=="grocery" or businessLine[i]=="pharmacy" or businessLine[i]=="restaurant")f=f;
            else f=false;
            if(!isActive[i])f=false;
            if(f)ans.push_back({businessLine[i],code[i]});
        }
        sort(ans.begin(),ans.end());
        vector<string>res;
        for(auto i:ans)res.push_back(i.second);
        return res;
    }
};