class Solution {
public:
    int bitwiseOR(vector<int> nums, int i, int j) {

        int ans = 0;
        for (int index = i; index <= j; index++)
            ans |= nums[index];

        return ans;
    }

    int minimumSubarrayLength(vector<int>& nums, int k) {

        int min_len = INT_MAX;
        bool flag = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i; j < nums.size(); j++) {
                if (bitwiseOR(nums, i, j) >= k) {
                    min_len = min(min_len, j - i + 1);
                    flag = 1;
                }
            }
        }

        if (flag == 0)
            return -1;

        return min_len;
    }
};
