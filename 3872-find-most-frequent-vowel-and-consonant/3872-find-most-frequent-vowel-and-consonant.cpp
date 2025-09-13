class Solution {
private:
    bool check(char ch){
        return ch=='a' || ch=='e' || ch=='i' || ch=='o'|| ch=='u';
    }
public:
    int maxFreqSum(string s) {
        int m1=0,m2=0;
        vector<int>frq(26,0);
        for(auto i:s){
            frq[i-'a']++;
            if(check(i))m1=max(m1,frq[i-'a']);
            else m2=max(m2,frq[i-'a']);
        }
        return m1+m2;
    }
};