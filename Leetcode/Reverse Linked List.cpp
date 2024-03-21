//Approach-1 (Using Recursion)
//T.C : O(m+n)
//S.C : O(1) (Ignoring recursion stack space)
class Solution {
public:
    
    ListNode* reverseSolve(ListNode* head) {
        if(!head || !head->next)
            return head;
        
        ListNode* last   = reverseSolve(head->next);
        head->next->next = head;
        head->next       = NULL;
            
        return last;
    }
    
    ListNode* reverseList(ListNode* head) {
        return reverseSolve(head);
    }
};
