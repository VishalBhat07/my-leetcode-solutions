class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {

        map<int, int> freq;
        int l = 0, r = 0;
        long long count = 0;

        while (r < nums.size()) {

            freq[nums[r]]++;

            while (freq.rbegin()->first - freq.begin()->first > 2) {
                freq[nums[l]]--;
                if (freq[nums[l]] == 0)
                    freq.erase(nums[l]);
                l++;
            }

            count += r - l + 1;
            r++;
        }

        return count;
    }
};
