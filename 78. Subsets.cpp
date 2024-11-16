class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        int n = nums.size();
        int subsets = 1 << n;
        vector<vector<int>> powerSet;

        for (int i = 0; i < subsets; i++) {
            vector<int> temp;

            for (int j = 0; j < n; j++)
                if (i & (1 << j))
                    temp.push_back(nums[j]);

            powerSet.push_back(temp);
        }

        return powerSet;
    }
};