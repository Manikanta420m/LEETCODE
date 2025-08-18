class Solution {
public:

    vector<double>fill(double a,double b){
        vector<double>v={a+b,a-b,b-a,a*b};
        if(a!=0)v.push_back(b/a);
        if(b!=0)v.push_back(a/b);
        return v;
    }

    bool solve(vector<double>&temp){
        if(temp.size()==1) return abs(temp[0]-24)<=0.1;

        for(int i=0;i<temp.size();i++){
            for(int j=i+1;j<temp.size();j++){
                vector<double>remL;
                for(int k=0;k<temp.size();k++){
                    if(k!=i and k!=j) remL.push_back(temp[k]);
                }
                vector<double>res;
                res=fill(temp[i],temp[j]);
                for(int l=0;l<res.size();l++){
                    remL.push_back(res[l]);
                    if(solve(remL))return true;
                    remL.pop_back();
                }
            }
        }
        return false;
    }

    bool judgePoint24(vector<int>& cards) {
        vector<double>temp(cards.begin(),cards.end());
        return solve(temp);
    }
};