class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int ans=0;
        int n=aliceValues.size();
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<n;i++){
            pq.push({aliceValues[i]+bobValues[i],i});
        }
        int alice=0,bob=0,f=1;
        while(!pq.empty()){
            int idx=pq.top().second;
            pq.pop();
            if(f){
               alice+=aliceValues[idx];
            }
            else{
               bob+=bobValues[idx];
            }
            f=!f;
        }
        return (alice==bob?0:(alice>bob)?1:-1);
    }
};