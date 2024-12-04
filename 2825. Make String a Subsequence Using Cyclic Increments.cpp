class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {

        int m = str1.size();
        int n = str2.size();
        if (n > m)
            return false;

        int first = -1, second = -1;
        while (first < m and second < n) {
            first++;
            second++;
            while (first < m) {
                char next_char = char((str1[first] - 'a' + 1) % 26 + int('a'));
                if (str2[second] == str1[first] or str2[second] == next_char)
                    break;
                first++;
            }
        }
        if (first == m and second < n)
            return false;
        return true;
    }
};
