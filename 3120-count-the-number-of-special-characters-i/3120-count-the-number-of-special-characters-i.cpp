class Solution {
public:
    int numberOfSpecialChars(string word) {
        bitset<26>a=0,A=0;
        for(auto i:word){
            if(i>='a')a[i-'a']=1;
            else A[i-'A']=1;
        }
        a=a&A;
        return a.count();
    }
};