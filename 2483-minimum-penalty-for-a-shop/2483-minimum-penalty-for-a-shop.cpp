class Solution {
public:
    int bestClosingTime(string customers) {
        int y=count(customers.begin(),customers.end(),'Y');
        int n=count(customers.begin(),customers.end(),'N');
        int cy=0,cn=0,maxi=y,ans=0;
        for(int i=0;i<customers.size();i++){
            if(customers[i]=='Y')cy++;
            else cn++;
            int res=(y-cy)+cn;
            if(res<maxi){
                maxi=res;
                ans=i+1;
            }
        }
        return ans;
    }
};