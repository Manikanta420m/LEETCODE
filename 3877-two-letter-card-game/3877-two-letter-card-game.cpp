class Solution {
private:
    int getPairs(int tot,int maxi){
        if(tot<=1)return 0;
        return min(tot/2,tot-maxi);
    }
public:
    int score(vector<string>& cards, char x) {
        map<char,int>mp1,mp2;
        int doubleX=0;
        string tar={x,x};
        
        for(auto i:cards){
            if(i.find(x)==string::npos)continue;
            if(i==tar)doubleX++;
            else if(i[0]==x)mp1[i[1]]++;
            else mp2[i[0]]++;
        }

        int leftTotal=0,leftMax=0;
        for(auto i:mp1){
            leftTotal+=i.second;
            leftMax=max(leftMax,i.second);
        }

        int rightTotal=0,rightMax=0;
        for(auto i:mp2){
            rightTotal+=i.second;
            rightMax=max(rightMax,i.second);
        }
       
        int ans=0;
        for(int i=0;i<=doubleX;i++){
            int tot1=leftTotal+i;
            int max1=max(leftMax,i);
            int score1=getPairs(tot1,max1);

            int tot2=rightTotal+(doubleX-i);
            int max2=max(rightMax,doubleX-i);
            int score2=getPairs(tot2,max2);

            ans=max(ans,score1+score2);
        }

        return ans;
    }
};