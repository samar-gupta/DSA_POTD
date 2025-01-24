class Solution {
  public:
    // Function to check if the linked list has a loop.
    bool detectLoop(Node* head) {
        // your code here
        if (head == NULL) return false;
        
        Node* fast = head, *slow = head;
        
        while (fast && fast -> next) {
            slow = slow -> next;
            fast = fast -> next -> next;
            
            if (fast == slow) {
                return true;
            }
        }
        
        return false;
    }
};
