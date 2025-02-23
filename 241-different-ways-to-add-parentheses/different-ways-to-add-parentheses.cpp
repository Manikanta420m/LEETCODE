class Solution {
public:
     int helper(int x,int y,char op){
        if(op=='+')return x+y;
         if(op=='-')return x-y;
          if(op=='*')return x*y;
          return 0;
     }

    vector<int> diffWaysToCompute(string expression) {
        vector<int>ans;
        bool f=1;
        for(int i=0;i<expression.size();i++){
             if(!isdigit(expression[i])){
                f=0;
                vector<int>left=diffWaysToCompute(expression.substr(0,i));
                vector<int>right=diffWaysToCompute(expression.substr(i+1));
                for(auto x:left){
                   for(auto y:right){
                        int val=helper(x,y,expression[i]);
                        ans.push_back(val);
                   }
                } 
             }
        }
        if(f)ans.push_back(stoi(expression));
        return ans;
    }
};