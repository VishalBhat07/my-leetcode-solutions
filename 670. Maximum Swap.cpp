class Solution {
public:
    int maximumSwap(int num) {

        if (num <= 10)
            return num;

        string val = to_string(num);
        int n = val.size();

        vector<int> right_max(n);

        right_max[n - 1] = n - 1;
        for (int i = n - 2; i >= 0; --i) 
            right_max[i] = (val[i] > val[right_max[i + 1]]) ? i : right_max[i + 1];

        for (int i = 0; i < n; i++) {
            if (val[right_max[i]] > val[i]) {
                swap(val[i], val[right_max[i]]);
                break;
            }
        }

        return stoi(val);
    }
};