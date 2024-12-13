class Solution {
public:
    long long findScore(vector<int>& nums) {

        long long score = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            minHeap;

        for (int i = 0; i < nums.size(); i++)
            minHeap.push({nums[i], i});

        while (!minHeap.empty()) {
            
            auto curr = minHeap.top();
            minHeap.pop();

            int num = curr.first;
            int idx = curr.second;

            if (nums[idx] != -1) {
                score += nums[idx];
                nums[idx] = -1;

                if (idx > 0 && nums[idx - 1] != -1)
                    nums[idx - 1] = -1;

                if (idx < nums.size() - 1 && nums[idx + 1] != -1)
                    nums[idx + 1] = -1;
            }
        }

        return score;
    }
};
