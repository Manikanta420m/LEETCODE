class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        long long siz=1;
        vector<long long>length;
        while(true){
            siz=siz*2LL;
            length.push_back(siz);
            if(siz>=k)break;
        }
        int turn=0;
        for(int i=length.size()-1;i>=0;i--){
            long long half=length[i]/2;
            int op=operations[i];
            if(k>half){
                k-=half;
                if(op==1)turn++;
            }
        }
        return (char)((('a'-'a'+turn)%26)+'a');
    }
};