class Solution
{
public:
    bool check(vector<int> piles, int h, int k)
    {
        int n = piles.size();
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (count > h)
                return false;
            if (k >= piles[i])
                count++;
            else if (piles[i] % k == 0)
                count += piles[i] / k;
            else
                count += piles[i] / k + 1;
        }
        return count <= h;
    }

    int minEatingSpeed(vector<int> &piles, int h)
    {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int mid = (l + r) / 2;

        while (l <= r)
        {
            if (check(piles, h, mid) == 1)
                r = mid - 1;
            else
                l = mid + 1;

            mid = (l + r) / 2;
        }
        return l;
    }
};