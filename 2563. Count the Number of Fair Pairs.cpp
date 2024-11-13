class Solution {
public:
    long long lowerBound(vector<int>& nums, int l, int r, int ele) {
        while (l <= r) {
            int mid = l + ((r - l) / 2);
            if (nums[mid] >= ele)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return l;
    }

    long long countFairPairs(vector<int>& nums, int lower, int upper) {

        sort(nums.begin(), nums.end());
        long long count = 0;
        for (int i = 0; i < nums.size(); i++) {

            int low = lowerBound(nums, i + 1, nums.size() - 1, lower - nums[i]);
            int high = lowerBound(nums, i + 1, nums.size() - 1, upper - nums[i] + 1);

            count += 1LL * (high - low);
        }
        return count;
    }
};
