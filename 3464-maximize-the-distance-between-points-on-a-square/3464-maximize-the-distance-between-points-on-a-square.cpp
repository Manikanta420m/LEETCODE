class Solution {
public:
   // O(nlogn + log(side) * nklog n)
    using ll = long long;
    vector<ll> dist;

    ll getPos(int x, int y, int side){
        if(x == 0) return y;
        if(y == side) return side + x;
        if(x == side) return 3LL * side - y;
        return 4LL * side - x;
    }

    bool f(ll x, int k, ll perimeter){
        int m = dist.size() / 2;

        for (int i = 0; i < m; i++) {
            ll first = dist[i];
            ll prev = first;
            int idx = i;
            int cnt = k - 1;

            while(cnt > 0){
                ll target = prev + x;
                auto it = lower_bound(begin(dist) + idx + 1, end(dist), target);

                if (it == dist.end() || *it > first + perimeter - x) break;

                prev = *it;
                idx = it - begin(dist);
                cnt--;
            }

            if(cnt == 0) return true;
        }
        return false;
    }

    int maxDistance(int side, vector<vector<int>>& points, int k) {
        int n = points.size();
        ll perimeter = 4LL * side;

        for(auto& p : points){
            int x = p[0];
            int y = p[1];

            dist.push_back(getPos(x, y, side));
        }

        sort(begin(dist), end(dist));

        for(int i = 0; i < n; ++i){
            dist.push_back(perimeter + dist[i]);
        }

        ll low = 0;
        ll high = perimeter / k;

        ll ans = 0;

        while(low <= high){
            ll mid = (low + high) >> 1;

            if(f(mid, k, perimeter)){
                ans = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return ans;
    }
};