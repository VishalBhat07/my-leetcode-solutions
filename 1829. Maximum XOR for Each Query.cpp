class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {

        int n = nums.size();
        vector<int> ans(n);

        int xorr = 0;
        for (int num : nums)
            xorr ^= num;

        int maxBitValue = pow(2, maximumBit) - 1;

        for (int i = 0; i < n; i++) {
            ans[i] = xorr ^ maxBitValue;
            xorr ^= nums[n - 1 - i];
        }
        return ans;
    }
};
