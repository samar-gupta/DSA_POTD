//Approach-1 :
//T.C : O(n)
//S.C : O(1)
class Solution {
  public:
    Node *reverse(Node *head) {
        // code here
        if (head->next == nullptr) return head;

        Node* curr = head;
        Node* temp = nullptr;

        while (curr != nullptr) {
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;
            curr = curr->prev;
        }

        if (temp != nullptr) head = temp->prev;

        return head;
    }
};


//old
class Solution {
  public:
    Node *reverse(Node *head) {
        // code here
        Node *curr = head;
        Node *next = NULL;
        Node *prev = NULL;
        while(curr)
        {
            next = curr->next;
            curr->prev = next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
        return head;
    }
};
