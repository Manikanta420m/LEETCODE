class Solution {
public:
    bool sumGame(string num) {
        int left=0,right=0;
        int n=num.size();
        int left_blank=0,right_blank=0;
        for(int i=0;i<n/2;i++){
            if(num[i]!='?') left+=(num[i]-'0');
            else left_blank++;
        } 
        for(int i=n/2;i<n;i++){
            if(num[i]!='?') right+=(num[i]-'0');
            else right_blank++;
        }
        if(left_blank + right_blank==0){
            return (left!=right);
        }
        if((left_blank+right_blank)%2==1) return true;
        int mini= min(left_blank,right_blank);
        left_blank-=mini;
        right_blank-=mini;
        
        if(left_blank>0){
            if(left>right) return true;
            if(9*(left_blank/2) == (right-left)) return false;
            else true;
        }
        else{
            if(right>left) return true;
            if(9*(right_blank/2) == (left-right)) return false;
            else true;
        }
        return true;
    }
};