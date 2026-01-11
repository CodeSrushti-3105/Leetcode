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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == nullptr) return ans;

        stack<TreeNode* > st;
        TreeNode *lastvisited = nullptr;
        TreeNode *temp = root;

        while(temp != nullptr || !st.empty()){
            while(temp != nullptr){
                st.push(temp);
                temp = temp -> left;
            }

            TreeNode *topNode = st.top();

            if(topNode -> right != nullptr && lastvisited != topNode -> right){
                temp = topNode -> right;
            }else{
                ans.push_back(topNode -> val);
                lastvisited = topNode;
                st.pop();
            }
        }
        return ans;
    }
};