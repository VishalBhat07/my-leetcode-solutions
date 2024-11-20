class Solution {
public:
    int takeCharacters(string s, int k) {

        vector<int> count(3, 0);

        for (char c : s)
            count[c - 'a']++;

        for (int i = 0; i < 3; i++)
            if (count[i] < k)
                return -1;

        vector<int> window(3, 0);
        int l = 0, maxWindow = 0;

        for (int r = 0; r < s.size(); r++) {
            window[s[r] - 'a']++;

            while (l <= r &&
                   (count[0] - window[0] < k || count[1] - window[1] < k ||
                    count[2] - window[2] < k)) {
                window[s[l] - 'a']--;
                l++;
            }

            maxWindow = max(maxWindow, r - l + 1);
        }

        return s.size() - maxWindow;
    }
};
