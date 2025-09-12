class Solution {
private:
    bool check(char ch){
        return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
    }
public:
    bool doesAliceWin(string s) {
        int cnt=0;
        for(auto i:s)cnt+=check(i);
        return cnt>=1;
    }
};