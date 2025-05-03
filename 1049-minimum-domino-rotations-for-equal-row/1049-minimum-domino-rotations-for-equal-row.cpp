class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        //Manikanta
        int ans=tops.size(),f=0;
        for(int i=1;i<=6;i++){
          int c1=0,c2=0;
           for(int j=0;j<tops.size();j++){
            if(tops[j]==i and bottoms[j]!=i)c1++;
            else if(tops[j]!=i and bottoms[j]==i)c2++;
            else if(tops[j]!=i and bottoms[j]!=i){c1=tops.size();c2=tops.size();f++;break;}
           }
           ans=min(ans,min(c1,c2));
        }return f==6?-1:ans;
    }
};