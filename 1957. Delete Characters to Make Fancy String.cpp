class Solution {
public:
    string makeFancyString(string s) {

        if (s.size() <= 2)
            return s;

        string ans = s.substr(0, 2);

        for (int i = 2; i < s.size(); i++)
            if (!(s[i - 2] == s[i - 1] && s[i - 1] == s[i]))
                ans += s[i];

        return ans;
    }
};