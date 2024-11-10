class Solution {
public:
    void updateFreq(vector<int>& bitFreq, int number, int val) {

        for (int i = 0; i < 32; i++) {
            if (number & (1 << i))
                bitFreq[i] += val;
        }
    }

    int getNumber(vector<int>& bitFreq) {

        int number = 0;

        for (int i = 0; i < 32; i++) {
            if (bitFreq[i] > 0)
                number += (1 << i);
        }
        return number;
    }

    int minimumSubarrayLength(vector<int>& nums, int k) {

        if (k == 0)
            return 1;

        int shortest = INT_MAX;
        int left = 0;
        int right = 0;
        int currOR = 0;

        vector<int> bitFreq(32);

        while (right < nums.size()) {

            updateFreq(bitFreq, nums[right], 1);
            currOR |= nums[right];

            while (left <= right && currOR >= k) {
                shortest = min(shortest, right - left + 1);
                updateFreq(bitFreq, nums[left], -1);
                currOR = getNumber(bitFreq);
                left++;
            }
            right++;
        }

        return (shortest == INT_MAX) ? -1 : shortest;
    }
};
