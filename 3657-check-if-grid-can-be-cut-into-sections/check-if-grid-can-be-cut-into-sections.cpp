class Solution {
public:
bool check(vector<vector<int>>& rectangles, int sortedWay) {
        int coordinateGap = 0;
        sort(rectangles.begin(), rectangles.end(), 
             [sortedWay](const vector<int>& a, const vector<int>& b) {
                 return a[sortedWay] < b[sortedWay];
             });
        
        int end = rectangles[0][sortedWay + 2];
        for (int i = 1; i < rectangles.size(); i++) {
            if (end <= rectangles[i][sortedWay]) {
                coordinateGap++;
            }
            end = max(end, rectangles[i][sortedWay + 2]);
        }
        return coordinateGap >= 2;
    }
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
          return check(rectangles, 0) || check(rectangles, 1);
    }
};