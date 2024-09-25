class Solution
{
public:
    int mySqrt(int x)
    {
        if (x == 0)
            return 0;

        if (x == 1)
            return 1;

        long long l = 1;
        long long r = x;
        long long mid = (l + r) / 2;

        while (l <= r)
        {
            if (mid * mid <= x)
                l = mid + 1;
            else
                r = mid - 1;

            mid = (l + r) / 2;
        }
        return (int)r;
    }
};