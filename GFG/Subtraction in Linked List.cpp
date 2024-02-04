class Solution {
private:
    int borrow = 0;  // Variable to keep track of borrow during subtraction

    // Function to reverse a linked list and return the new head
    Node* reverse(Node* head) {
        Node* curr = head, *tmp, *prev = NULL; 
        while (curr) tmp = curr->next, curr->next = prev, prev = curr, curr = tmp; 
        return prev;
    }
    
    // Function to calculate the length of a linked list
    int len(Node *head) {
        int l = 0;
        Node* tmp = head;
        while(tmp) tmp = tmp->next, l++;
        return l;
    }

    // Function to perform subtraction of two linked lists
    Node* sub(Node* a, Node* b) {
        if (a == NULL && b == NULL) return NULL;
        if (b == NULL) {
            int diff = a->data - borrow;
            if (diff < 0) diff += 10, borrow = 1;
            else borrow = 0;
            Node* nn = new Node(diff);
            nn->next = sub(a->next, b);
            return nn;
        }
        int diff = a->data - b->data - borrow;
        if (diff < 0) diff += 10, borrow = 1;
        else borrow = 0;
        Node* nn = new Node(diff);
        nn->next = sub(a->next, b->next);
        return nn;
    }
    
    // Function to remove initial zeros and return new head
    Node* remove_initial_zeros(Node* head) {
        while (head && head->data == 0) head = head->next;
        return head;
    }

public:
    // Main function to subtract two linked lists representing numbers
    Node* subLinkedList(Node* a, Node* b) {
        a = remove_initial_zeros(a), b = remove_initial_zeros(b);
        
        if (a == NULL && b == NULL) return new Node(0);
        else if (a == NULL) return b;
        else if (b == NULL) return a; 
        
        int l1 = len(a), l2 = len(b); 
        if (l1 < l2) swap(a, b);
        else if(l1 == l2){
            Node *t1 = a, *t2 = b; 
            while (t1 && t1->data == t2->data) t1 = t1->next, t2 = t2->next; 
            if (t1 == NULL) return new Node(0);
            if(t1->data < t2->data) swap(a, b);
        }
      
        return remove_initial_zeros( reverse( sub( reverse(a), reverse(b) ) ) );
    }
};
