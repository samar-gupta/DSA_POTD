//Approach-1 : 
class Solution {
  public:
    Node* findFirstNode(Node* head) {
        // your code here
        if (head == NULL || head->next == NULL) return NULL; // No loop
        
        Node *slow = head, *fast = head;
        
        // Step 1: Detect if there's a loop using two pointers (Floyd's Algorithm)
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;       // move slow pointer one step
            fast = fast->next->next; // move fast pointer two steps
            
            // If slow and fast meet, a loop exists
            if (slow == fast) {
                break;
            }
        }
        
        // Step 2: If no loop is detected
        if (fast == NULL || fast->next == NULL) {
            return NULL; // No loop
        }
        
        // Step 3: Find the first node of the loop
        slow = head; // reset slow to the head
        
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        
        // Both pointers meet at the first node of the loop
        return slow;
    }
};


//Approach-2 : 
class Solution {
  public:
    Node* findFirstNode(Node* head) {
        // your code here
        Node *temp = head;
        
        if(head == NULL) {
            return -1;
        }
        
        while(temp != NULL) {
            if(temp->data < 0) {
                return -(temp->data);
            }
            temp->data = -(temp->data);
            temp = temp->next;
        }
        
        return -1;
    }
};
