class NumberContainers {
public:
    //I AM A FIGHTER
    unordered_map<int,set<int>>small;
    unordered_map<int,int>ind;
    NumberContainers() {
    }
    
    void change(int index, int number) {
        if(ind.find(index)!=ind.end()){
            int old=ind[index];
            small[old].erase(index);
            if(small[old].empty())small.erase(old);
        }
        ind[index]=number;
        small[number].insert(index);
    }
    
    int find(int number) {
        if(small.find(number)==small.end())return -1;
        return *small[number].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */