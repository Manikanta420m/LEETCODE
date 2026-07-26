class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n=nums.size();
        int a=-1001,b=a,c=b;
        int x=1001,y=x;
        for(auto i:nums){
           // int pa=a,pb=b,px=x;
            
            
            c=max(c,min(b,i));
            b=max(b,min(a,i));
            a=max(i,a);
            y=min(y,max(x,i));
            x=min(x,i);
            
        }
        return max(a*b*c,a*x*y);
    }
};