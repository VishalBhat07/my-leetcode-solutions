class Solution {
public:
    string s;

    bool helper(int i, int j) {

        if (i >= j)
            return true;

        if (!isalnum(s[i]))
            return helper(i + 1, j);
        else if (!isalnum(s[j]))
            return helper(i, j - 1);
        else if (tolower(s[i]) == tolower(s[j]))
            return helper(i + 1, j - 1);

        return false;
    }

    bool isPalindrome(string ques) {

        s = ques;
        return helper(0, s.size() - 1);
    }
};
