class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i1=0,i2=0;
        int n1=version1.size(),n2=version2.size();

        while(i1<n1 || i2<n2){
            //int j1=i1,j2=i2;
            // while(j1<n1 and version1[j1]!='.')++j1;
            // while(j2<n2 and version2[j2]!='.')++j2;

            int num1=0,num2=0;
            while(i1<n1 and version1[i1]!='.')num1=num1*10+(version1[i1++]-'0');
            while(i2<n2 and version2[i2]!='.')num2=num2*10+(version2[i2++]-'0');

            if(num1<num2)return -1;
            if(num1>num2)return 1;

            i1++;
            i2++;
        }
        return 0;
    }
};