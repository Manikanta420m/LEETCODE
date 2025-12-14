class Solution {
public:
    static const long long M=1e9+7;
    int numberOfWays(string corridor) {
        long long ans=1;
        int n=corridor.size();
        int cnt=count(corridor.begin(),corridor.end(),'S');
        if(cnt&1 or cnt==0)return 0;
        if(cnt==2)return 1;
        else{
           long long c=0,temp=1;
           for(int i=0;i<n;i++){
             if(corridor[i]=='S'){
                if(c%2==0 and c>1){
                   ans=(ans*temp)%M;
                   c++;
                }
                else c++;
                temp=1;
             }
             else{
               if(c%2==0)temp++;
             }
           }
        }
        return (int)ans;
    }
};