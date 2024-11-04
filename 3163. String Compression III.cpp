class Solution {
public:
    string compressedString(string word) {

        string comp = "";
        int i = 0;

        while (i < word.size()) {
            int count = 0;
            char currentChar = word[i];

            while (i < word.size() && word[i] == currentChar) {
                if (count >= 9)
                    break;
                count++;
                i++;
            }
            comp += to_string(count) + currentChar;
        }
        return comp;
    }
};