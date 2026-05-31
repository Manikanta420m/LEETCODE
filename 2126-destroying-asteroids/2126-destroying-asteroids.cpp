class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long sm=mass;
        sort(asteroids.begin(),asteroids.end());
        for(auto i:asteroids){
            if(i<=sm)sm+=i;
            else return false;
        }
        return true;
    }
};