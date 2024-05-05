//Company Tags   : Apple, Adobe, Microsoft, Samsung
//Leetcode Link  : https://leetcode.com/problems/delete-node-in-a-linked-list/

//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* prev = NULL;
        
        while(node && node->next) {
            node->val = node->next->val;
            prev = node;
            node = node->next;
        }
        delete(node);
        prev->next = NULL;
    }
};
