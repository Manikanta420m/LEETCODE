class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int>temp;
        unordered_set<int>ans;
        // unordered_map<int,int>mp;
        // for(int i=0;i<digits.size();i++){
        //     mp[digits[i]]++;
        //     if(mp[digits[i]]<=3)temp.push_back(digits[i]);
        // }
        for(int i=0;i<digits.size();i++){
            for(int j=0;j<digits.size();j++){
                if(i==j or digits[i]==0)continue;
                for(int k=0;k<digits.size();k++){
                    if(k==j or k==i)continue;
                    if(digits[k]%2==0){
                        ans.insert(digits[i]*100+digits[j]*10+digits[k]);
                    }
                }
            }
        }
        vector<int>ansi(ans.begin(),ans.end());
        sort(ansi.begin(),ansi.end());
        return ansi;
    }
};