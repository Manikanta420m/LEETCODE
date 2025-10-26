class Bank {
public:
    unordered_map<int,long long>mp;

    Bank(vector<long long>& balance) {
        for(int i=1;i<=balance.size();i++){
            mp[i]=balance[i-1];
        }
    }
    
    bool transfer(int account1, int account2, long long money) {
    if((account1<=mp.size() and account2<=mp.size()) and mp[account1]>=money){
           mp[account1]-=money;
           mp[account2]+=money;
           return true;
        }
        else return false;
    }
    
    bool deposit(int account, long long money) {
        if(account>mp.size())return false;
        mp[account]+=money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if(account<=mp.size() and mp[account]>=money){
            mp[account]-=money;
            return true;
        }
        else return false;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */