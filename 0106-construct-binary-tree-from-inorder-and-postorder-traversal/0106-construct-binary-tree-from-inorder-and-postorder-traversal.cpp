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
    unordered_map<int , int> inorderIndex;
    int postorderIndex;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        postorderIndex = postorder.size() - 1;

        for(int i = 0;i < inorder.size();i++){
            inorderIndex[inorder[i]] = i;
        }
        return build(inorder,postorder,0,inorder.size()-1);
    }

    TreeNode* build(vector<int>& inorder, vector<int>& postorder,int left,int right){
        if(left > right) return nullptr;

        int rootval = postorder[postorderIndex--];
        TreeNode* root = new TreeNode(rootval);

        int mid = inorderIndex[rootval];

        root -> right = build(inorder,postorder,mid+1,right);
        root -> left = build(inorder,postorder,left,mid-1);
        

        return root;
    }
};