//Leetcode Link : https://leetcode.com/problems/evaluate-boolean-binary-tree/description/

//Approach : (Using simple recursion)
//T.C : O(n)
//S.C : O(depth of tree)
class Solution {
public:
    bool evaluateTree(TreeNode* root) {
        if(root->left == NULL && root->right == NULL) {
            return root->val;
        }
        
        if(root->val == 2) {
            return evaluateTree(root->left) | evaluateTree(root->right);
        }
        
        return evaluateTree(root->left) & evaluateTree(root->right);
    }
};
