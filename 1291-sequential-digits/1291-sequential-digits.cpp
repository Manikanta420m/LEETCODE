class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>ans;
        // int siz=log10(low)+1;
        // int lmt=log10(high)+2;
       for(int i=1;i<=9;i++){
            int num=i;
            int nxt=i+1;
            while(num<=high and nxt<=9){
                num=num*10+nxt;
                if(low<=num and num<=high)ans.push_back(num);
                nxt++;
            }
       }
       sort(ans.begin(),ans.end());
       return ans;
    }
};