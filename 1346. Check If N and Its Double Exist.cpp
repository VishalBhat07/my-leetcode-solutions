class Solution {
public:
    bool checkIfExist(vector<int>& arr) {

        map<int, int> hash;

        for (int num : arr) {

            if (hash.count(2 * num) || (num % 2 == 0 && hash.count(num / 2)))
                return true;

            hash[num]++;
        }
        return false;
    }
};
