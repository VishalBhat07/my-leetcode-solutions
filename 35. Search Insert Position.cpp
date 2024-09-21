class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        int l = 0;
        int r = nums.size() - 1;
        int mid = (l + r) / 2;
        int ans = nums.size();

        while (l <= r) {

            if (nums[mid] >= target) {
                ans = min(ans, mid);
                r = mid - 1;
            } else
                l = mid + 1;
                
            mid = (l + r) / 2;
        }
        return ans;
    }
};