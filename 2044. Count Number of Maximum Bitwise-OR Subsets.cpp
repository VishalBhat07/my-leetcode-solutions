class Solution {
public:
    int calcSubsetOR(vector<int> nums) {

        int maxOR = 0;
        for (int i = 0; i < nums.size(); i++)
            maxOR |= nums[i];

        return maxOR;
    }

    int countMaxOrSubsets(vector<int>& nums) {

        int count = 0;
        int maxOR = 0;
        int n = nums.size();

        maxOR = calcSubsetOR(nums);

        for (int i = 0; i < (1 << n); i++) {
            vector<int> temp;
            for (int j = 0; j < n; j++) {
                if ((i & (1 << j)) != 0) {
                    temp.push_back(nums[j]);
                }
            }
            if (calcSubsetOR(temp) == maxOR)
                count++;
        }
        return count;
    }
};