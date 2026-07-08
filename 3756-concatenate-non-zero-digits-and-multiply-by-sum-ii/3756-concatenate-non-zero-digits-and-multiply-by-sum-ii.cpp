class Solution {
public:
    const int M=1e9+7;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n=s.size();
        // vector<int>res;
        // vector<long long>pre(n,0);
        // pre[0]=s[0]-'0';
        // for(int i=1;i<n;i++){
        //     pre[i]=(pre[i-1]+(int)(s[i]-'0'))%M;
        // }
        // vector<int>zero(n,0);
        // vector<string>strs;
        // int c=0;
        // string s1="";
        // for(int i=0;i<n;i++){
        //     if(s[i]-'0'==0)c++;
        //     pre[i]=c;
        //     if(s[i]!='0')s1+=s[i];
        //     strs.push_back(s1);
        // }
        // for(auto i:queries){
        //     int l=i[0],r=i[1];
        //     if(r==0){
        //         res.push_back(0);
        //         continue;
        //     }
        //     int prez=0,siz=0;
        //     if(l>0)prez=zero[l-1];
        //     if(l==0)siz=zero[r];
        //     else siz=zero[r]-zero[l-1];
        //     string x=strs[r-1];
        //     string temp=x.substr(l-prez,r-l-siz+1);
        //     res.push_back((int)(stoll(temp))%M);
        // }
        // return res;
        vector<long long>prenum(n+1,0),presum(n+1,0),precnt(n+1,0),pw(n+1,1);
        for(int i=1;i<=n;i++)pw[i]=(pw[i-1]*10)%M;
        for(int i=0;i<n;i++){
            int c=s[i]-'0';
            prenum[i+1]=prenum[i];
            precnt[i+1]=precnt[i];
            presum[i+1]=presum[i];
            if(c!=0){
                precnt[i+1]++;
                presum[i+1]+=c;
                prenum[i+1]=(prenum[i]*10+c)%M;
            }
        }
        vector<int>ans;
        for(auto i:queries){
            int l=i[0],r=i[1];
            long long cnt=precnt[r+1]-precnt[l];
            long long sm=presum[r+1]-presum[l];
            if(cnt==0){
                ans.push_back(0);
                continue;
            }
            long long sumDigits = presum[r+1] - presum[l];
            long long rig=prenum[r+1];
            long long lf=prenum[l];
            long long sf=(lf*pw[cnt])%M;
            rig=(rig-sf)%M;
            if(rig<0)rig+=M;
            long long res = (rig % M) * (sumDigits % M) % M;
            ans.push_back(res);
        }
        return ans;
    }
};