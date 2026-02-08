//Company Tags  : Adobe, Apple, Capgemini, Meta, CBSL Group (India)
//Leetcode Link : https://leetcode.com/problems/balanced-binary-tree

//Approach : Using simple recursion
//T.C : O(n^2)
//S.C : O(n)
class Solution {
public:
    int height(TreeNode* root) {

        if(!root)
            return 0;

        int leftH  = height(root->left);
        int rightH = height(root->right);

        return max(leftH, rightH) + 1;
    }

    bool isBalanced(TreeNode* root) {
        if(!root) {
            return true;
        }
        
        int leftH  = height(root->left);
        int rightH = height(root->right);

        if(abs(leftH - rightH) > 1)
            return false;
        
        return isBalanced(root->left) && isBalanced(root->right);
    }
};
