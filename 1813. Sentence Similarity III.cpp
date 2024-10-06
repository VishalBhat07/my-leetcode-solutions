class Solution {
public:
    vector<string> convertToWords(string sentence) {

        vector<string> words;
        int j = 0;

        for (int i = 0; i <= sentence.size(); i++) {
            if (i == sentence.size() || sentence[i] == ' ') {
                words.push_back(sentence.substr(j, i - j));
                j = i + 1;
            }
        }
        return words;
    }

    bool areSentencesSimilar(string sentence1, string sentence2) {

        vector<string> words1 = convertToWords(sentence1);
        vector<string> words2 = convertToWords(sentence2);

        if (words1.size() < words2.size())
            swap(words1, words2);

        int start = 0, end = 0;
        int n1 = words1.size(), n2 = words2.size();

        while (start < n2 && words1[start] == words2[start])
            start++;

        while (end < n2 && words1[n1 - end - 1] == words2[n2 - end - 1])
            end++;

        return start + end >= n2;
    }
};