class Solution {
public:
    bool isPalindrome(int x) {

        if (x < 0)
            return false;

        long long revNum = 0;
        int num = x;

        while (num != 0) {
            revNum = revNum * 10 + (num % 10);
            num /= 10;
        }

        return revNum == x;
    }
};
