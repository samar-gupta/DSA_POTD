//Approach - Optimal (O(n)) using min and max value for |min-max|
class Solution {
public:
    
    int findMaxDiff(TreeNode* root, int minV, int maxV) {
        if(!root)
            return abs(minV-maxV);
        
        minV = min(root->val, minV);
        maxV = max(root->val, maxV);

        int l = findMaxDiff(root->left,  minV, maxV);
        int r = findMaxDiff(root->right, minV, maxV);


        return max(l, r);
    }

    int maxAncestorDiff(TreeNode* root) {
        int minV = root->val;
        int maxV = root->val;

        return findMaxDiff(root, minV, maxV);
    }
};






//Approach-1 (Brute Force) - O(n^2) - n = number of nodes in the Tree

//Just simply taking a root, find all the differences of it from its children and find max one
//Again go to root->left and do the same as above
//Again go to root->right and do the same as above

class Solution {
public:
    int maxDiff;

    void findMaxUtil(TreeNode* root, TreeNode* child) {
        if(!root || !child)
            return;
        
        maxDiff = max(maxDiff, abs(root->val - child->val));

        findMaxUtil(root, child->left);
        findMaxUtil(root, child->right);
    }

    void findMaxDiff(TreeNode* root) {
        if(!root || !root->left && !root->right)
         return;
         
         //Find max differences of this root with all its children
         findMaxUtil(root, root->left);
         findMaxUtil(root, root->right);

         //firther move left and right
         findMaxDiff(root->left);
         findMaxDiff(root->right);
    }

    int maxAncestorDiff(TreeNode* root) {
        maxDiff = INT_MIN;

        findMaxDiff(root);   

        return maxDiff;     
    }
};
