class Solution {

    bool canAssign(vector<int>& nums, int val, int operations) {
        int count = 0;
        for (int& ele : nums) {
            if (ele > val)
                count += ceil((double)(ele - val) / val);
        }
        return count <= operations;
    }

public:
    int minimumSize(vector<int>& nums, int maxOperations) {

        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int mid;
        int res = INT_MAX;

        while (low <= high) {
            mid = low + (high - low) / 2;

            if (canAssign(nums, mid, maxOperations)) {
                res = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return res;
    }
};
