class Solution {
public:
    int reverse(int x) {

        int revNum = 0;
        int num = x;

        while (num != 0) {
            if (revNum > INT_MAX / 10 || revNum < INT_MIN / 10)
                return 0;
            revNum = revNum * 10 + (num % 10);
            num = num / 10;
        }

        return revNum;
    }
};
