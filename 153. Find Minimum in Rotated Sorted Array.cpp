class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int l = 0;
        int r = nums.size() - 1;
        int mid = (l + r) / 2;
        int ans = INT32_MAX;

        while (l <= r)
        {

            if (nums[l] <= nums[mid])
            {
                ans = min(nums[l], ans);
                l = mid + 1;
            }
            else
            {
                ans = min(nums[mid], ans);
                r = mid - 1;
            }

            mid = (l + r) / 2;
        }
        return ans;
    }
};