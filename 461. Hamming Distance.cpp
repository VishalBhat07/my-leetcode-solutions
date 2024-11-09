class Solution {
public:
    int hammingDistance(int x, int y) {

        int req = x ^ y;
        int cnt = 0;

        while (req != 0) {
            cnt++;
            req = req & req - 1;
        }

        return cnt;
    }
};
