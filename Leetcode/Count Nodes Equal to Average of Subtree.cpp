/*
    Company Tags                : Similar Qn Asked by Google for N-ary tree(SWE Intern Position, 2nd Technical Interview) , Year = 2023, September
    Leetcode Link               : https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree
*/

/************************************************ C++ ************************************************/
//Approach-2 (Doing postorder traversal)
//T.C : O(n)
//S.C : O(1) (excluding recursion stack space)
class Solution {
public:

    int result;

    pair<int, int> solve(TreeNode* root) {
        if(!root) {
            return {0, 0};
        }

        auto P1 = solve(root->left);
        auto P2 = solve(root->right);

        int totalSum = P1.first + P2.first + root->val;
        int totalCount = P1.second + P2.second + 1;

        int avg = totalSum/totalCount;

        if(avg == root->val) {
            result += 1;
        }

        return {totalSum, totalCount};
    }

    int averageOfSubtree(TreeNode* root) {
        result = 0;

        solve(root);

        return result;
    }
};




//Approach-1 (Brute Force)
//T.C : O(n^2) For every root, you visit it's subtree to find average
//S.C : O(1) (excluding recursion stack space)
class Solution {
public:
    int result;
    
    int sum(TreeNode* root, int &count) {
        if(!root)
            return 0;
        
        count++;
        
        int l = sum(root->left, count);
        int r = sum(root->right, count);
        
        return l + r + root->val;
    }
    
    void solve(TreeNode* root) {
        if(!root)
            return;
        
        int count = 0;
        int totalSum = sum(root, count);
        
        if((totalSum)/count == root->val) {
            result++;
        }
        
        solve(root->left);
        solve(root->right);
        
    }
    
    int averageOfSubtree(TreeNode* root) {
        result = 0;
        
        solve(root);
        
        return result;
    }
};
