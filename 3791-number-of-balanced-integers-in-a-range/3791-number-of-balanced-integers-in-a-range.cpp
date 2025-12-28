class Solution {
public:
    
    long long solve(int idx,int dif,bool tight,bool st,map<tuple<int,int,bool,bool>,long long>&mp,string s){
         if(idx==s.size())return (st and dif==0);
         auto key=make_tuple(idx,dif,tight,st);
         if(mp.count(key))return mp[key];
         int lmt=(tight?s[idx]-'0':9);
         long long res=0;
         for(int i=0;i<=lmt;i++){
            bool nst=(st||i);
            int ndif=dif;
            if(nst){
                if((idx+1)&1)ndif+=i;
                else ndif-=i;
            }
            res+=solve(idx+1,ndif,tight&&i==lmt,nst,mp,s);
         }
         return mp[key]=res;
    }

    long long len(long long n){
        if(n<=10)return 0;
        map<tuple<int,int,bool,bool>,long long>mp;
        string s=to_string(n);
        return solve(0,0,true,false,mp,s);
    }

    long long countBalanced(long long low, long long high) {
      return len(high)-len(low-1);   
    }
};