class Solution {
private:
    void funPos(char ch,int &x,int &y){
        if(ch=='U')y++;
        else if(ch=='D')y--;
        else if(ch=='L')x--;
        else x++;
    }
    void funNeg(char ch,int &x,int &y){
        if(ch=='U')y--;
        else if(ch=='D')y++;
        else if(ch=='L')x++;
        else x--;
    }
public:
    int distinctPoints(string s, int k) {
        int x=0,y=0;
        if(s.size()==k)return 1;
        for(int i=0;i<s.size();i++){
            funPos(s[i],x,y);
        }
        set<pair<int,int>>st;
        for(int i=0;i<s.size();i++){
            if(i>=k){
              funPos(s[i-k],x,y);
              funNeg(s[i],x,y);
              st.insert({x,y});
            }
            else{
                funNeg(s[i],x,y);
                if(i==k-1)st.insert({x,y});
            }
        }
        
        return st.size();
    }
};