class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {

        unordered_map<long long, int> mpp;

        for (int num : nums) {
            mpp[num] = 1;
        }

        int max_length = -1;

        for (int num : nums) {
            int length = 0;
            long long current = num;

            while (mpp.count(current)) {
                length++;
                current *= current; 
            }

            if (length >= 2) 
                max_length = max(max_length, length);
        }

        return max_length;
    }
};