//Company Tags   : Oracle
//Leetcode Link  : https://leetcode.com/problems/remove-nth-node-from-end-of-list/

//Approach-1 (2 Pass)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    
    int lengthLinkedList(ListNode* head) {
        int l = 0;
        
        while(head) {
            l++;
            head = head->next;
        }
        return l;
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = lengthLinkedList(head);
        
        if(length == n) { //Length node from end means first node  i.e (head)
            ListNode* temp = head->next;
            delete(head);
            return temp;
        }

        ListNode* temp = head;
        ListNode* prev = NULL;
        int travel = length-n;
        
        while(travel--) {
            prev = temp;
            temp = temp->next;
        }

        prev->next = temp->next;
        
        delete(temp);   
        
        return head;
    }
};





//Approach-2 (1 Pass)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;
        
        for(int i = 1; i <= n; i++) {
            fast = fast->next;
        }
        if(fast == NULL) {
            return head->next;
        }
        
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        
        ListNode* temp = slow->next;
        slow->next = slow->next->next;
        delete(temp);
        return head;
    }
};
