class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {

        priority_queue<long long> maxheap(nums.begin(), nums.end());

        long long ans = 0;

        for (int j = 0; j < k; j++) {

            long long curr = maxheap.top();
            maxheap.pop();

            int max_index = nums.size() - 1;
            ans += curr;

            curr = ceil((double)curr/3);
            maxheap.push(curr);
        }
        return ans;
    }
};