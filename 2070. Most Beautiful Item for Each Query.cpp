class Solution {
public:
    int helper(vector<vector<int>>& items, int query) {

        int l = 0;
        int r = items.size() - 1;
        int mid = (l + r) / 2;
        int maxBeauty = 0;

        while (l <= r) {
            if (items[mid][0] <= query) {
                l = mid + 1;
                maxBeauty = max(maxBeauty, items[mid][1]);
            } else
                r = mid - 1;

            mid = (l + r) / 2;
        }

        return maxBeauty;
    }

    vector<int> maximumBeauty(vector<vector<int>>& items,
                              vector<int>& queries) {

        vector<int> ans;
        sort(items.begin(), items.end());

        for (int i = 1; i < items.size(); i++)
            items[i][1] = max(items[i][1], items[i - 1][1]);

        for (auto query : queries)
            ans.push_back(helper(items, query));

        return ans;
    }
};
