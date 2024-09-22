class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int l = 0;
        int r = nums.size() - 1;
        int mid = (l + r) / 2;

        while (l <= r)
        {
            if (nums[mid] == target)
                return mid;

            if (nums[l] <= nums[mid])
            {
                if ((nums[l] <= target) && (target <= nums[mid]))
                    r = mid - 1;
                else
                    l = mid + 1;
            }
            else
            {
                if ((nums[mid] <= target) && (target <= nums[r]))
                    l = mid + 1;
                else
                    r = mid - 1;
            }
            mid = (l + r) / 2;
        }
        return -1;
    }
};