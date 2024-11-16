class Solution {
public:
    int helper(vector<int> nums, int l, int r) {

        int ans = -1;
        for (int i = l + 1; i <= r; i++)
            if (nums[i] < nums[i - 1] || (abs(nums[i] - nums[i - 1]) != 1))
                return -1;

        return nums[r];
    }

    vector<int> resultsArray(vector<int>& nums, int k) {

        int l = 0;
        int r = k - 1;
        vector<int> ans;

        while (r < nums.size()) {
            ans.push_back(helper(nums, l, r));
            l++;
            r++;
        }
        return ans;
    }
};
