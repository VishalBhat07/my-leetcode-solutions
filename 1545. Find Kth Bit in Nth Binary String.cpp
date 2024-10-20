class Solution {
public:
    char findKthBit(int n, int k) {

        string s = "0";

        for (int i = 0; i < n; i++) {
            string front = s;

            for (int j = 0; j < s.size(); j++)
                s[j] = s[j] == '1' ? '0' : '1';

            reverse(s.begin(), s.end());

            s = front + '1' + s;
        }

        return s[k - 1];
    }
};