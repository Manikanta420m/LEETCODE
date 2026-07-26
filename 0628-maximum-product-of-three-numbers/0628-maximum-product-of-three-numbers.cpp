class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n=nums.size();
        int a=-1001,b=a,c=b;
        int x=1001,y=x;
        for(auto i:nums){
            int pa=a,pb=b,px=x;
            a=max(i,a);
            b=max(b,min(pa,i));
            c=max(c,min(pb,i));
            x=min(x,i);
            y=min(y,max(px,i));
        }
        return max(a*b*c,a*x*y);
    }
};