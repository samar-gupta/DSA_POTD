class Solution {
  public:
    
    // Function to reverse a circular linked list
    Node* reverse(Node* head) {
        Node* Prev = NULL;
        Node* Curr = head;
        Node* Next = Curr->next;
        
        while(Next != head){
            Curr->next = Prev;
            Prev = Curr;
            Curr = Next;
            Next = Next->next;
        }
        // at this point next = head & Curr = last node
        Next->next = Curr;
        Curr->next = Prev;
        
        return Curr;
    }

    // Function to delete a node from the circular linked list
    Node* deleteNode(Node* head, int key) {
        Node* temp = head->next;
        Node* ptr = head;
        
        if(head->data == key){
            while(ptr->next != head)
                ptr = ptr->next;
            
            ptr->next = temp;
            delete head;
            
            return temp;
        }
        
        else{
            while(temp->data != key && temp != head){
                ptr = temp;
                temp = temp->next;
            }
            if(temp->data == key){
                ptr->next = temp->next;
                delete temp;
            }
        }
        
        return head;
    }
};
