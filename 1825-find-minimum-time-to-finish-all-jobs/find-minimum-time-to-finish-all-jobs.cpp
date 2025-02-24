class Solution {
public:

    bool check(int idx,int & mid,vector<int>&work,vector<int>& jobs, int k){
         if(idx==jobs.size())return true;
         for(int i=0;i<k;i++){
            if(work[i]+jobs[idx]<=mid){
                work[i]+=jobs[idx];
                if(check(idx+1,mid,work,jobs,k))return true;
                work[i]-=jobs[idx];
            }
            if(work[i]==0)return false;
         }return false;
    }

    int minimumTimeRequired(vector<int>& jobs, int k) {
        int l=*max_element(jobs.begin(),jobs.end());
        int h=accumulate(jobs.begin(),jobs.end(),0);
        while(l<=h){
            int mid=l+(h-l)/2;
            vector<int>work(k,0);
            if(check(0,mid,work,jobs,k))h=mid-1;
            else l=mid+1;
        }return l;
    }
};