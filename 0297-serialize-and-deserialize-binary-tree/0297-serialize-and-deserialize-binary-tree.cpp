/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void serializeHelper(TreeNode* root, string& s){
        if(root == nullptr){
            s += "#,";
            return;
        }
        s += to_string(root -> val) + ",";
        serializeHelper(root -> left, s);
        serializeHelper(root -> right, s);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        serializeHelper(root,s);
        return s;
    }

    TreeNode* deserializeHelper(vector<string> &nodes, int &i){
        if(nodes[i] == "#"){
            i++;
            return nullptr;
        }

        TreeNode* root = new TreeNode(stoi(nodes[i]));
        i++;
        root -> left = deserializeHelper(nodes, i);
        root -> right = deserializeHelper(nodes, i);

        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> nodes;
        string temp = "";

        for(char c : data){
            if(c == ','){
                nodes.push_back(temp);
                temp = "";
            }else{
                temp += c;
            }
        }
        int i = 0;
        return deserializeHelper(nodes , i);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));