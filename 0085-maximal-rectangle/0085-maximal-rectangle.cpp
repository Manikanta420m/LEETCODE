class Solution {
public:
     vector<int>previ(vector<int>& a){
        int n=a.size();
        vector<int>ans(n);
        stack<int>s;
        s.push(-1);
        for(int i=0;i<n;i++){
           while(s.top()!=-1&&a[s.top()]>=a[i])s.pop();
           ans[i]=s.top();
           s.push(i);
        }return ans;
    }
    vector<int>nexti(vector<int>& a){
        int n=a.size();
        vector<int>ans(n);
        stack<int>s;
        s.push(-1);
        for(int i=n-1;i>=0;i--){
           while(s.top()!=-1&&a[s.top()]>=a[i])s.pop();
           ans[i]=s.top();
           s.push(i);
        }return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        int area=INT_MIN;
        vector<int>next;
        next=nexti(heights);
        vector<int>prev;
        prev=previ(heights);
        for(int i=0;i<n;i++){
            int len=heights[i];
            if(next[i]==-1)next[i]=n;
            int bre=next[i]-prev[i]-1;
            area=max(area,bre*len);
        }return area;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>p(m,0);
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1')p[j]++;
                else p[j]=0;
            }
            maxi=max(maxi,largestRectangleArea(p));
        }return maxi;
    }
};