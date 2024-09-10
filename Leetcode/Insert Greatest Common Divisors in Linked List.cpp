//Leetcode Link : https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list

//Approach-1 (Iterative)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head || !head->next) {
            return head;
        }

        ListNode* currNode = head;
        ListNode* nextNode = head->next;

        while(nextNode) {
            ListNode* temp = new ListNode(__gcd(currNode->val, nextNode->val));

            currNode->next = temp;
            temp->next     = nextNode;

            currNode = nextNode;
            nextNode = nextNode->next;
        }

        return head;
    }
};


//Approach-2 (Recursion Story)
//T.C : O(n)
//S.C : System stack space due to recursion O(n)
class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        // Base case: if head is null or there's only one node, return head.
        if (!head || !head->next) {
            return head;
        }

        // Recursively process the rest of the list
        ListNode* temp = insertGreatestCommonDivisors(head->next);

        // Create a new node with the GCD of current and next node values
        ListNode* gcdNode = new ListNode(__gcd(head->val, head->next->val));

        // Insert the new node between the current node and the next node
        gcdNode->next = temp;
        head->next = gcdNode;

        // Return the current node
        return head;
    }
};
