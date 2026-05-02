class NumArray {
int n=0;
vector<int>bit;
vector<int>numi;
private:
   void upd(int idx,int x){
      for(int i=idx;i<=n;i+=(i&(-i))){
         bit[i]+=x;
      }
   }
   int sum(int idx){
    int ans=0;
      for(int i=idx;i>0;i-=(i&(-i))){
         ans+=bit[i];
      }
      return ans;
   }
public:
    NumArray(vector<int>& nums) {
        n=nums.size();
        bit.resize(n+1,0);
        for(int i=0;i<n;i++){
            upd(i+1,nums[i]);
        }
        numi.resize(n+1,0);
        for(int i=0;i<n;i++)numi[i+1]=nums[i];
    }
    
    void update(int index, int val) {
        upd(index+1,val-numi[index+1]);
        numi[index+1]=val;
    }
    
    int sumRange(int left, int right) {
        return sum(right+1)-sum(left);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */