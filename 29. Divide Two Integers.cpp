class Solution {
public:
    int divide(int dividend, int divisor) {

        if (dividend == divisor)
            return 1;

        bool sign = (dividend < 0 == divisor < 0);

        unsigned int n = abs(dividend);
        unsigned int q = abs(divisor);
        unsigned int ans = 0;

        while (n >= q) {
            int cnt = 0;
            while (n > (q << (cnt + 1)))
                cnt++;
            ans += (1 << cnt);
            n -= (q << cnt);
        }

        if (ans == (1 << 31) && sign == true)
            return INT_MAX;

        return sign ? ans : -ans;
    }
};
