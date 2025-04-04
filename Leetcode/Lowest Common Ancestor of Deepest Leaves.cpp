//Leetcode Link : https://leetcode.com/classic/problems/lowest-common-ancestor-of-deepest-leaves/description/
//Same Question on Leetcode : https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/
   
//Approach-1 (Using 2 Pass Solution and LCA code)
//T.C : O(2*n) ~= O(n)
//S.C : O(maxDepth) System stack space
class Solution {
public:
    unordered_map<int, int> mp;
    int maxD = 0;

    TreeNode* LCA(TreeNode* root) {
        if(root == NULL || mp[root->val] == maxD) {
            return root;
        }

        TreeNode* l = LCA(root->left);
        TreeNode* r = LCA(root->right);

        if(l && r) {
            return root;
        }

        return l != NULL ? l : r;
    }

    void depth(TreeNode* root, int d) {
        if(!root) {
            return;
        }

        maxD = max(maxD, d);
        mp[root->val] = d;
        depth(root->left, d+1);
        depth(root->right, d+1);
    }
    //T.C : O(n)
    //S.C : O(maxD) system recursion stack space
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        depth(root, 0);

        return LCA(root);
    }
};


//Approach-2 (Using 1 Pass Solution)
//T.C : O(n)
//S.C : O(maxDepth) System stack space
class Solution {
public:
    pair<int, TreeNode*> solve(TreeNode* root) {
        if(root == NULL) {
            return {0, NULL};
        }

        auto l = solve(root->left);
        auto r = solve(root->right);

        if(l.first == r.first) {
            return {l.first+1, root};
        } else if(l.first > r.first) {
            return {l.first+1, l.second};
        } else {
            return {r.first+1, r.second};
        }
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return solve(root).second;   
    }
};
