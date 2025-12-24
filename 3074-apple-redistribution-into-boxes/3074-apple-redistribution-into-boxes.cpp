class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
       sort(capacity.rbegin(),capacity.rend());
       int sm=accumulate(apple.begin(),apple.end(),0);
       for(int i=0;i<capacity.size();i++){
        sm-=capacity[i];
        if(sm<=0)return i+1;
       } 
       return capacity.size();
    }
};