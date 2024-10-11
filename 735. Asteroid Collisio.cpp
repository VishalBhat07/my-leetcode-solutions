class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        vector<int> st;

        for (auto it : asteroids) {

            while (!st.empty() && it < 0 && st.back() > 0) {

                int sum = st.back() + it;

                if (sum < 0)
                    st.pop_back();
                else if (sum > 0)
                    it = 0;
                else {
                    st.pop_back();
                    it = 0;
                }
            }

            if (it != 0)
                st.push_back(it);
        }

        return st;
    }
};