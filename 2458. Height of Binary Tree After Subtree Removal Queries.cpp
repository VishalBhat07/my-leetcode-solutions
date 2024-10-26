/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {

    int findHeight(TreeNode* curr, int level, vector<int>& node_level,
                   vector<int>& node_height,
                   vector<pair<int, int>>& top2_height) {

        if (!curr)
            return 0;

        int height = 1 + max(findHeight(curr->left, level + 1, node_level,
                                        node_height, top2_height),
                             findHeight(curr->right, level + 1, node_level,
                                        node_height, top2_height));

        node_level[curr->val] = level;
        node_height[curr->val] = height;

        if (height > top2_height[level].first) {
            top2_height[level].second = top2_height[level].first;
            top2_height[level].first = height;
        } else if (height > top2_height[level].second) {
            top2_height[level].second = height;
        }

        return height;
    }

public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {

        int n = 100001;
        vector<int> node_height(n, 0);
        vector<int> node_level(n, -1);
        vector<pair<int, int>> top2_height(n, {0, 0});

        findHeight(root, 0, node_level, node_height, top2_height);

        vector<int> result;

        for (int query : queries) {
            int level = node_level[query];
            int height = node_height[query];

            int max_height = (top2_height[level].first == height)
                                 ? top2_height[level].second
                                 : top2_height[level].first;

            result.push_back(max_height + level - 1);
        }

        return result;
    }
};