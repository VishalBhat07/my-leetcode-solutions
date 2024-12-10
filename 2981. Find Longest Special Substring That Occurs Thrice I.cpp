class Solution {
public:
    int maximumLength(string s) {

        map<string, int> count;
        for (int i = 0; i < s.length(); i++) {
            string currString;
            for (int j = i; j < s.length(); j++) {
                if (currString.empty() or currString.back() == s[j]) {
                    currString.push_back(s[j]);
                    count[currString]++;
                } else {
                    break;
                }
            }
        }

        int ans = 0;
        for (auto it : count) {
            string str = it.first;
            if (it.second >= 3 && str.length() > ans)
                ans = str.length();
        }
        if (ans == 0)
            return -1;
        return ans;
    }
};
