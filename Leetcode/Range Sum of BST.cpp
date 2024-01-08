//Leetcode Link  : https://leetcode.com/problems/range-sum-of-bst/
//Company Tags : Google, Amazon, D.E. Shaw, Meta
//T.C - O(n)
//S.C - O(1) (Ignoging recursion stack space)
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root == NULL)
            return 0;
        
        //Within Range
        if(root->val >= low && root->val <= high) {
            return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
        }
        
        //(waste to go left) When outside the range (Less than low) - Go right
        if(root->val < low)
            return rangeSumBST(root->right, low, high);

        //(waste to go right) When outside the range (Greater than high) - Go left
        return rangeSumBST(root->left, low, high);
    }
};
