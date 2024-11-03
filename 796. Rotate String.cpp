class Solution {
public:
    bool rotateString(string s, string goal) {

        int j = 0;
        while (j < s.size()) {
            char temp = s[0];
            for (int i = 0; i < s.size(); i++) {
                s[i] = s[i + 1];
            }
            s[s.size() - 1] = temp;
            j++;
            if (s == goal)
                return true;
        }
        return false;
    }
};