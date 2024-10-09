class Solution {
public:
    int minAddToMakeValid(string s) {

        stack<char> st;
        int c = 0;

        for (int i = 0; i < s.size(); i++) {

            if (s[i] == '(')
                st.push(s[i]);
            else {
                if (st.empty())
                    c++;
                else
                    st.pop();
            }
        }

        return c + st.size();
    }
};