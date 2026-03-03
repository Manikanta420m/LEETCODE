class Solution {
public:
    char findKthBit(int n, int k) {
         int sel=k&(-k);
         bool inv=(((k/sel)>>1)&1)==1;
         bool org=(k&1)==0;
         if(inv)return org==1?'0':'1';
         else return org==1?'1':'0';
    }
};