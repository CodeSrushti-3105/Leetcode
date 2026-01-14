/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
    if (root == NULL) return 0;

    long long ans = 0;
    queue<pair<TreeNode*, long long>> q;
    q.push({root, 0});

    while (!q.empty()) {
        int size = q.size();
        long long start = q.front().second;
        long long end = q.back().second;

        ans = max(ans, end - start + 1);

        for (int i = 0; i < size; i++) {
            pair<TreeNode*, long long> curr = q.front();
            q.pop();

            TreeNode* node = curr.first;
            long long idx = curr.second - start;

            if (node->left != NULL)
                q.push({node->left, 2 * idx});

            if (node->right != NULL)
                q.push({node->right, 2 * idx + 1});
        }
    }
    return ans;
}

};