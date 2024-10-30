class Solution {

    vector<int> LIS(vector<int> nums) {

        int n = nums.size();
        vector<int> lis;
        vector<int> lis_len(n, 1);

        for (int i = 0; i < n; i++) {
            int lb = lower_bound(lis.begin(), lis.end(), nums[i]) - lis.begin();

            if (lb >= lis.size())
                lis.push_back(nums[i]);
            else
                lis[lb] = nums[i];

            lis_len[i] = lis.size();
        }

        return lis_len;
    }

public:
    int minimumMountainRemovals(vector<int>& nums) {

        int n = nums.size();

        vector<int> lis_LR = LIS(nums);
        reverse(nums.begin(), nums.end());

        vector<int> lis_RL = LIS(nums);
        reverse(lis_RL.begin(), lis_RL.end());

        int max_mountain_size = 0;
        for (int i = 0; i < n; i++)
            if (lis_LR[i] > 1 && lis_RL[i] > 1 &&
                (lis_LR[i] + lis_RL[i] - 1) > max_mountain_size)
                max_mountain_size = lis_LR[i] + lis_RL[i] - 1;

        return n - max_mountain_size;
    }
};