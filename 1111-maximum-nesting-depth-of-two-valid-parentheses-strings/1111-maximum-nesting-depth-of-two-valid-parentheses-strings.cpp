class Solution { 
public: 
    vector<int> maxDepthAfterSplit(string seq) { 
        vector<int> ans(seq.size());
        int depth = 0;
        for (int i = 0; i < seq.size(); ++i) {
            if (seq[i] == '(') {
                ++depth;
                ans[i] = depth % 2;
            } else {
                ans[i] = depth % 2;
                --depth;
            }
        }
        return ans;
    } 
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna