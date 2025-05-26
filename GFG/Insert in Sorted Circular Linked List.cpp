// Approach: Traverse the circular linked list using two pointers (curr and nextToCurr) to find the correct position to insert the new node such that the list remains sorted. There are 3 cases to handle: inserting in the middle of two nodes, inserting as the new minimum (before current head), or inserting as the new maximum (at the wrap-around point).
// Time Complexity: O(n) In the worst case, we may traverse all 'n' nodes in the circular linked list once to find the correct insertion point.
// Space Complexity: O(1) Only a constant amount of extra space is used for pointers and the new node.

class Solution {
public:
    Node* sortedInsert(Node* head, int data) {
        // Step 1: Create the new node with given data
        Node* newNode = new Node(data);

        // Step 2: Initialize two pointers
        Node* curr       = head;
        Node* nextToCurr = head->next;

        // Step 3: Traverse the circular list to find correct insertion point
        while (true) {
            // Case 1: Normal case — insert between two nodes in sorted order
            if (curr->data <= data && data <= nextToCurr->data) {
                break;
            }

            // Case 2: Turning point (from max to min)
            // This means curr is at the largest element, and nextToCurr is at the smallest
            if (curr->data > nextToCurr->data) {
                // Insert at wrap-around if:

                // - data is smaller than current min or
                // - data is greater than current max
                if (data <= nextToCurr->data || data >= curr->data) {
                    break;
                }
            }

            // Move both pointers ahead in the circular list
            curr       = curr->next;
            nextToCurr = nextToCurr->next;
        }

        // Step 4: Insert the new node between curr and nextToCurr
        curr->next    = newNode;
        newNode->next = nextToCurr;

        // Step 5: If inserted before head (i.e., new minimum), return newNode as new head
        return (data < head->data) ? newNode : head;
    }
};
