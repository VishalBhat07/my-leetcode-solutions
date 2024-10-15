class Solution {
public:
    long long minimumSteps(string s) {

        long long count0s = 0; 
        long long swaps = 0;   

        for (int i = s.size() - 1; i >= 0; i--) {

            if (s[i] == '0') 
                count0s++; 

            if (s[i] == '1') 
                swaps += count0s; 
        }
        return swaps;
    }
};