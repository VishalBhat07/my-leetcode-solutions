class Solution {
public:
    int n;
    int range;
    vector<vector<int>> dp;

    int helper(int i, int sum, vector<int>& A, int t) {

        if (i >= n)
            return sum == t;

        if (dp[i][sum + range] != -1)
            return dp[i][sum + range];

        int takePositive = helper(i + 1, sum + A[i], A, t);
        int takeNegative = helper(i + 1, sum - A[i], A, t);

        return dp[i][sum + range] = takePositive + takeNegative;
    }

    int findTargetSumWays(vector<int>& nums, int target) {

        n = nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        range = totalSum;
        dp.resize(n, vector<int>(2 * totalSum + 1, -1));
        return helper(0, 0, nums, target);
    }
};
