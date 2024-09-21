class Solution {
  public:
    Node *copyList(Node *head) {
        // Write your code here
        Node* newNode = new Node(head->data);
        Node* temp = newNode;
        while(head->next != NULL) {
            temp->next = head->next;
            temp->random = head->random;
            temp = temp->next;
            head = head->next;
        }
        return newNode;
    }
};
