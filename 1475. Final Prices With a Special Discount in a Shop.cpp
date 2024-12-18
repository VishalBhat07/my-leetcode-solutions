class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {

        vector<int> result = prices;

        for (int i = 0; i < prices.size(); i++) {
            for (int j = i + 1; j < prices.size(); j++) {
                if (prices[j] <= prices[i]) {
                    result[i] = prices[i] - prices[j];
                    break;
                }
            }
        }

        return result;
    }
};
