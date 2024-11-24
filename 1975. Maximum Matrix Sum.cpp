class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {

        long long total = 0;
        int minAbsVal = INT_MAX;
        int negatives = 0;

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                total += abs(matrix[i][j]);
                if (matrix[i][j] < 0)
                    negatives++;
                minAbsVal = min(minAbsVal, abs(matrix[i][j]));
            }
        }

        if (negatives % 2 != 0)
            total -= 2 * minAbsVal;

        return total;
    }
};
