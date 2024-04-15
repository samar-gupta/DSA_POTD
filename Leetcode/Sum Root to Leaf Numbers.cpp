//Company Tags    : Google, Meta, Accolite, Amazon, Microsoft, Samsung, FactSet, Housing.com, Oracle, Goldman Sachs, Adobe, Coupon Dunia, Atlassian
//Leetcode Link   : https://leetcode.com/problems/sum-root-to-leaf-numbers/

//Approach - (Recursion)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    
    int find(TreeNode* root, int curr) {
        
        if(!root)
            return 0;
        
        curr = curr*10 + root->val;
        
        if(root->left == NULL && root->right == NULL) {
            return curr;
        }
        
        int left_num  = find(root->left, curr);
        int right_num = find(root->right, curr);
        
        return left_num + right_num;
    }
    
    int sumNumbers(TreeNode* root) {
        return find(root, 0);
    }
};
