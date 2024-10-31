class Solution {
  public:
    Node* sortedInsert(Node* head, int x) {
        // Code here
        // Declare the node to be inserted
        Node *newNode = getNode(x);
        // The list is empty
        // Insert the node and return the single element
        if (head == NULL) {
            return newNode;
        }
        // The first element is greater than the node value to be inserted
        // Insert before the head
        if (head->data >= x) {
            newNode->next = head;
            head->prev = newNode;
            return newNode;
        }
        // Traverse the list
        // Find the element after which node is to be inserted
        Node *temp = head;
        while (temp->next != NULL) {
            if (temp->next->data >= x) break;     // Node to be inserted after temp
            temp = temp->next;
        }
        // Insert the node after temp
        Node *front = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next = front;
        if (front != NULL) {    // when temp is the last element
            front->prev = newNode;
        }
        return head;
    }
};
