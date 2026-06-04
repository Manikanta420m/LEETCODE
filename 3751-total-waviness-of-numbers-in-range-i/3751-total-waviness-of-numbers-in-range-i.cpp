class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int ans=0;
        for(int i=num1;i<=num2;i++){
            string temp=to_string(i);
            int siz=(int)temp.size();
            if(siz<=2)continue;
            for(int j=1;j<siz-1;j++){
                int lf=temp[j-1]-'0';
                int rf=temp[j+1]-'0';
                int cur=temp[j]-'0';
                if((cur>lf and cur>rf) || (cur<lf and cur<rf))ans++;
            }
        }
        return ans;
    }
};