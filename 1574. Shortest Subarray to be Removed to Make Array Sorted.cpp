class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {

        int l = 0;
        int r = arr.size() - 1;

        while (r > 0 && arr[r - 1] <= arr[r])
            r--;

        int shortest = r;

        while (l < r) {
            while (r < arr.size() && arr[l] > arr[r])
                r++;

            shortest = min(shortest, r - l - 1);

            l++;
            if (arr[l - 1] > arr[l])
                break;
        }
        return shortest;
    }
};
