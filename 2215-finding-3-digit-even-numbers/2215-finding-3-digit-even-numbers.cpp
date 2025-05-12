// class Solution {
// public:
//     vector<int> findEvenNumbers(vector<int>& digits) {
//         vector<int>temp;
//         unordered_set<int>ans;
//         for(int i=0;i<digits.size();i++){
//             for(int j=0;j<digits.size();j++){
//                 if(i==j or digits[i]==0)continue;
//                 for(int k=0;k<digits.size();k++){
//                     if(k==j or k==i)continue;
//                     if(digits[k]%2==0){
//                         ans.insert(digits[i]*100+digits[j]*10+digits[k]);
//                     }
//                 }
//             }
//         }
//         vector<int>ansi(ans.begin(),ans.end());
//         sort(ansi.begin(),ansi.end());
//         return ansi;
//     }
// };
// https://leetcode.com/problems/finding-3-digit-even-numbers/solutions/6735949/100-beat-make-3-list-for-3-pos-and-then-simply-traverse-them-must-check
using namespace std;

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int freq[10] = {0};
        for (int i : digits) freq[i]++;

        int last[10], middle[10], first[10], res[900];
        int n1 = 0, n2 = 0, n3 = 0, size = 0;

        for (int i = 0; i < 10; i++) {
            if (freq[i] == 0) continue;
            if (i % 2 == 0) last[n3++] = i;
            if (i > 0) first[n1++] = i;
            middle[n2++] = i;
        }

        for (int i = 0; i < n1; i++) {
            for (int j = 0; j < n2; j++) {
                for (int k = 0; k < n3; k++) {
                    int a = first[i], b = middle[j], c = last[k];
                    int x = a * 100 + b * 10 + c;

                    if (a != b && b != c && a != c) {
                        res[size++] = x;
                    } else if ((a == b && b != c) || (a == c && a != b)) {
                        if (freq[a] > 1) res[size++] = x;
                    } else if (b == c && a != b) {
                        if (freq[b] > 1) res[size++] = x;
                    } else if (freq[a] > 2) {
                        res[size++] = x;
                    }
                }
            }
        }

        vector<int> ans(size);
        for (int i = 0; i < size; i++) ans[i] = res[i];
        return ans;
    }
};