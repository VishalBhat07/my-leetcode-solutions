class Solution {
public:
    int largestCombination(vector<int>& candidates) {

        int n = candidates.size();
        int max_freq = 0;

        for (int i = 0; i < 32; i++) {
            int freq = 0;
            for (auto& ele : candidates)
                if (ele & (1 << i))
                    freq++;

            max_freq = max(freq, max_freq);
        }

        return max_freq;
    }
};