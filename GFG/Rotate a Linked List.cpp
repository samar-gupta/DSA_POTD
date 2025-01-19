//Approach-1 : 
class Solution {
  public:
    Node* rotate(Node* head, int k) {
        // Your code here
        if (head == NULL || head->next == NULL || k == 0) {
            return head; // No rotation needed
        }

        // Find the length of the linked list
        Node* curr = head;
        int len = 1;
        while (curr->next != NULL) {
            curr = curr->next;
            len++;
        }

        // Update k to avoid unnecessary rotations
        k = k % len;
        if (k == 0) {
            return head; // No rotation needed
        }

        // Connect the last node to the head to form a circular list
        curr->next = head;

        // Traverse to the k-th node
        Node* newTail = head;
        for (int i = 1; i < k; i++) {
            newTail = newTail->next;
        }

        // The node after newTail becomes the new head
        Node* newHead = newTail->next;

        // Break the circular connection
        newTail->next = NULL;

        return newHead;
    }
};


//Approach-1 : 
class Solution {
  public:
    Node* rotate(Node* head, int k) {
        if (!head || !head->next || k == 0) return head;
        Node* temp = head;
        int n = 1;
        while (temp->next) {
            temp = temp->next;
            n++;
        }
        k = k % n;
        if (k == 0) return head;
        temp->next=head;
        Node* t=head;
        while(k>1){
            t=t->next;
            k--;
        }
        head=t->next;
        t->next=NULL;
        return head;
    }
};
