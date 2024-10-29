class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {

        int sum = 0;
        int boxes = 0;

        sort(capacity.begin(), capacity.end(), greater<int>());

        for (auto it : apple)
            sum += it;

        for (auto it : capacity) {
            sum -= it;
            boxes++;

            if (sum <= 0)
                break;
        }

        return boxes;
    }
};