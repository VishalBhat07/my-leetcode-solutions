class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {

        int t_friend = times[targetFriend][0];
        int n = times.size();

        priority_queue<int, vector<int>, greater<int>> available;
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            reserved;

        sort(times.begin(), times.end());

        for (auto& t : times) {

            while (!reserved.empty() && reserved.top().first <= t[0]) {
                available.push(reserved.top().second);
                reserved.pop();
            }

            if (t[0] == t_friend)
                break;

            if (available.empty())
                reserved.push({t[1], reserved.size()});
            else {
                reserved.push({t[1], available.top()});
                available.pop();
            }
        }

        return available.empty() ? reserved.size() : available.top();
    }
};