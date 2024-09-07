//Leetcode Link : https://leetcode.com/problems/linked-list-in-binary-tree/description/

//Approach-1 (Simple recursion)
//T.C : O(n*m) , n = number of nodes in trees, m = number of nodes in linkedlist. For every node in tree as starting node we will try matching with m nodes in list
//S.C : O(1) , but since we are running recursion we will take system resurcion stack = O(m+n)
class Solution {
public:

    bool check(ListNode* head, TreeNode* root) {
        if(!head) {
            return true;
        }

        if(!root || root->val != head->val) {
            return false;
        }

        return check(head->next, root->left) || check(head->next, root->right);
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        if(!root) {
            return false;
        }
        return check(head, root)        || 
               isSubPath(head, root->left)  || 
               isSubPath(head, root->right);
    }
};
