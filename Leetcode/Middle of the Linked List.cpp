//Company Tags                : Adobe, Amazon, Flipkart, GE, Hike, IgniteWorld, MAQ Software, Microsoft, Morgan Stanley, 
                                  Nagarro, Netskope, Payu, Qualcomm, Samsung, SAP Labs, Veritas, VMWare, Wipro, Zoho
//Leetcode Link               : https://leetcode.com/problems/middle-of-the-linked-list/

//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow  = head;
        ListNode* fast = head;
        
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
};
