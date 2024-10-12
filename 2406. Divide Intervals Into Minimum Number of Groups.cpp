class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {

        vector<pair<int, int>> events;

        for (int i = 0; i < intervals.size(); i++) {
            events.push_back({intervals[i][0], 1});
            events.push_back({intervals[i][1] + 1, -1});
        }

        sort(events.begin(), events.end());

        int max_overlap = 0;
        int overlap = 0;

        for (int i = 0; i < events.size(); i++) {
            events[i].second == 1 ? overlap++ : overlap--;
            max_overlap = max(overlap,max_overlap);
        }
        return max_overlap;
    }
};