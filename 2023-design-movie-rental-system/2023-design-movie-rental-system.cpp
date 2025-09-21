class MovieRentingSystem {
private:
    map<int,set<pair<int,int>>>avail_movies;
    set<tuple<int,int,int>>rented_movies;
    map<pair<int,int>,int>prices;
public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for(auto i:entries){
            int shop=i[0];
            int movie=i[1];
            int price=i[2];

            prices[{shop,movie}]=price;
            avail_movies[movie].insert({price,shop});
        }
    }
    
    vector<int> search(int movie) {
        vector<int>ans;
        if(avail_movies.count(movie)){
             auto &shops=avail_movies.at(movie);
             int cnt=0;
             for(auto i:shops){
                if(cnt>=5)break;
                ans.push_back(i.second);
                cnt++;
             }
        }
        return ans;
    }
    
    void rent(int shop, int movie) {
        int price=prices.at({shop,movie});
        avail_movies.at(movie).erase({price,shop});
        rented_movies.insert({price,shop,movie});
    }
    
    void drop(int shop, int movie) {
        int price=prices.at({shop,movie});
        rented_movies.erase({price,shop,movie});
        avail_movies.at(movie).insert({price,shop});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>>ans;
        int cnt=0;
        for(auto i:rented_movies){ 
            if(cnt>=5)break;
            ans.push_back({get<1>(i),get<2>(i)});
            cnt++;
        }  
        return ans;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */