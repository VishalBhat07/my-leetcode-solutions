class Solution {
public:
    bool canAssign(int mid, int n, vector<int> quantities) {

        int count = 0;

        for (int i = 0; i < quantities.size(); i++)
            count += ceil((double)quantities[i] / mid);

        return count <= n;
    }

    int minimizedMaximum(int n, vector<int>& quantities) {

        int l = 1;
        int r = *max_element(quantities.begin(), quantities.end());
        int mid = l + (r - l) / 2;
        int ans = INT_MAX;

        while (l <= r) {

            if (canAssign(mid, n, quantities)) {
                ans = min(ans, mid);
                r = mid - 1;
            } else
                l = mid + 1;

            mid = l + (r - l) / 2;
        }

        return ans;
    }
};
