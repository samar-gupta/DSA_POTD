//Leetcode Link : https://leetcode.com/problems/binary-tree-postorder-traversal/

//Approach-1 : (Simple Recursion)
class Solution {
public:

    void postOrder(TreeNode* root, vector<int>& result) {
        if(!root) {
            return;
        }

        postOrder(root->left, result);
        postOrder(root->right, result);
        result.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        postOrder(root, result);

        return result;
    }
};
