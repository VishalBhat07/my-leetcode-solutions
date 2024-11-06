class Solution {
public:
    int setBitCount(int n) {

        int count = 0;
        while (n != 0) {
            if (n % 2)
                count++;
            n /= 2;
        }

        return count;
    }

    bool canSortArray(vector<int>& nums) {

        for (int i = 0; i < nums.size() - 1; i++)
            for (int j = 0; j < nums.size() - i - 1; j++)
                if (nums[j] > nums[j + 1] &&
                    setBitCount(nums[j]) == setBitCount(nums[j + 1]))
                    swap(nums[j], nums[j + 1]);

        for (int i = 0; i < nums.size() - 1; i++)
            if (nums[i + 1] < nums[i])
                return false;

        return true;
    }
};
