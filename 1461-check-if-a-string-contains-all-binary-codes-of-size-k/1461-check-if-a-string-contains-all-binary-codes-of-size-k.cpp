class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int req=1<<k;
        bitset<1048576>vis;
        int mask=req-1;
        int num=0;
        for(int i=0;i<s.size();i++){
            num=((num<<1)&mask)|((s[i]-'0')&1);
            if(i>=k-1 and !vis[num]){
                vis[num]=1;
                req--;
                if(req==0)return true;
            }
        }
        return false;
    }
};