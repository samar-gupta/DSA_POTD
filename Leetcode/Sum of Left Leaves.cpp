//Company Tags   : META
//Leetcode Link  : https://leetcode.com/problems/sum-of-left-leaves/

//Approach-1 (Using Parent Pointer)
//T.C : O(n)
//S.C : O(1) Auxiiliary Space and O(depth of tree) recursion system stack space
class Solution {
public:
    int sum(TreeNode* curr, TreeNode* parent) {
        if(!curr)
            return 0;
        
        int left  = sum(curr->left, curr);
        int right = sum(curr->right, curr);
        
        int sum = 0;
        if(curr->left == NULL && curr->right == NULL) {
            if(parent && parent->left == curr)
                sum += curr->val;
        }
        
        return left+right+sum;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root)
            return 0;
        TreeNode* parent = NULL;
        return sum(root, parent);
    }
};



//Approach-2 (without parentpointer, only using a flag)
//T.C : O(n)
//S.C : O(1) Auxiiliary Space and O(depth of tree) recursion system stack space
class Solution {
public:
    
    int solve(TreeNode* curr, bool isLeft) {
        if(!curr) {
            return 0;
        }
        
        if(!curr->left && !curr->right && isLeft) {
            return curr->val;
        }
        
        return solve(curr->left, true) + solve(curr->right, false);
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        return solve(root, false);
    }
};
