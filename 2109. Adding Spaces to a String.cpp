class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {

        stringstream result;
        int spaceIndex = 0;

        for (int i = 0; i < s.size(); ++i) {
            if (spaceIndex < spaces.size() && i == spaces[spaceIndex]) {
                result << ' ';
                ++spaceIndex;
            }
            result << s[i];
        }
        return result.str();
    }
};
