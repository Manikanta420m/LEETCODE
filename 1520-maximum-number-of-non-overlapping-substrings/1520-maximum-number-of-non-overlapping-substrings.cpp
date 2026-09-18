class Solution {
    
    vector<string> funct(int left, int right, string &s, vector<int> &first, vector<int> &last, vector<int> &freq){
        vector<string> ans;

        for(int i = 0; i<26; i++){
            if(freq[i] == 0)
                continue;

            if(left <= first[i] && last[i] <= right){
                if(freq[i] == last[i] - first[i] + 1)
                    ans.push_back(s.substr(first[i], last[i]-first[i]+1));
            }
        }

        if(ans.size() == 0){
            while(left <= right && s[left] == s[right] && freq[s[left]-'a'] == 2){
                left++;
                right--;
            }  
            return {s.substr(left, right-left+1)};
        }

        return ans;
    }

public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.length();;
        vector<int> freq(26, 0), first(26, n), last(26, -1);
        vector<string> ans;

        for(int i=0; i<n; i++){
            freq[s[i]-'a']++;
            first[s[i]-'a'] = min(first[s[i]-'a'], i);
            last[s[i]-'a'] = i;
        }

        int left=0, right = 0;

        for(int i=0; i<n; i++){
            right = max(right, last[s[i]-'a']);

            if(i == right){
                auto temp = funct(left, right, s, first, last, freq);
                ans.insert(ans.end(), temp.begin(), temp.end());
                left = i+1;
            }
        }
        return ans;
    }
};