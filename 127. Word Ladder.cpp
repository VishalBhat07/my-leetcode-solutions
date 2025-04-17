class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {

        queue<pair<string, int>> q;
        unordered_set<string> st(wordList.begin(), wordList.end());

        q.push({beginWord, 1});
        st.erase(beginWord);

        while (!q.empty()) {

            string curr = q.front().first;
            int steps = q.front().second;
            q.pop();

            if(curr == endWord) return steps;

            for (int i = 0; i < curr.size(); i++) {
                char original = curr[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    curr[i] = ch;
                    if (st.find(curr) != st.end()) {
                        q.push({curr, steps + 1});
                        st.erase(curr);
                    }
                }
                curr[i] = original;
            }
        }
        return 0;
    }
};
