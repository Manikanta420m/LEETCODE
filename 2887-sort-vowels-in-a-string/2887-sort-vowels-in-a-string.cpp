class Solution {
private:
    bool check(char ch){
        if(ch=='a' || ch=='e' ||ch=='i' || ch=='o' || ch=='u')return true;
        if(ch=='A' || ch=='E' ||ch=='I' || ch=='O' || ch=='U')return true;
        return false;
    }
public:
    string sortVowels(string s) {
        vector<char>v;
        for(auto i:s){
            if(check(i))v.push_back(i);
        }
        sort(v.begin(),v.end());
        int j=0;
        for(auto &i:s){
            if(check(i))i=v[j++];
        }
        return s;
    }
};