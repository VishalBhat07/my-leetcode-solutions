class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {

        long long ans = 0;
        long long currentSum = 0;
        int l = 0;
        int r = 0;

        unordered_map<int, int> numToIndex;

        while (r < nums.size()) {
            int currNum = nums[r];
            int lastOccurrence = (numToIndex.count(currNum) ? numToIndex[currNum] : -1);

            while (l <= lastOccurrence || r - l + 1 > k) {
                currentSum -= nums[l];
                l++;
            }
            
            numToIndex[currNum] = r;
            currentSum += nums[r];

            if (r - l + 1 == k) 
                ans = max(ans, currentSum);

            r++;
        }
        return ans;
    }
};
