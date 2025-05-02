class Solution {
public:
    string pushDominoes(string dominoes) {
     dominoes='L'+dominoes+'R';
     string ans;
     int prev=0;
     for(int i=1;i<dominoes.size();i++){
        if(dominoes[i]=='.')continue;
        int siz=i-prev-1;
        if(prev>0)ans+=dominoes[prev];
        if(dominoes[prev]==dominoes[i]){
            ans+=string(siz,dominoes[prev]);
        }
        else if(dominoes[prev]=='L' && dominoes[i]=='R'){
            ans+=string(siz,'.');
        }
        else{
            ans+=string(siz/2,'R')
                +string(siz%2,'.')
                +string(siz/2,'L');
        }
        prev=i;
     }return ans;
    }
};