//Approach-1 : (Using Recursion)
class Solution {
  public:
    Node* reverse(Node* head, Node* stop) {
        Node* prev = stop;
        while (head != stop) {
            Node* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
    
    Node *reverseKGroup(Node *head, int k) {
        // code here
        Node* curr = head;
     
        for (int i = 0; i < k; i++) {
            if (curr == nullptr) 
                return reverse(head, nullptr);
            curr = curr->next;
        }

        Node* newHead = reverse(head, curr);
        head->next = reverseKGroup(curr, k);
        return newHead;
    }
};


//Approach-2 : (Interative)
class Solution {
  public:
    void reverse(Node* head, Node* stop) {
        Node* prev = stop;
        while (head != stop) {
            Node* nxt = head->next;
            head->next = prev;
            prev = head;
            head = nxt;
        }
    }
    
    Node *reverseKGroup(Node *head, int k) {
        // code here
        if (k <= 1) return head;

        Node dummy(0);
        dummy.next = head;
        Node* prev = &dummy;

        while (true) {
            
            Node* end = prev;
            int count = 0;
            
            while (count < k && end->next != nullptr) {
                end = end->next;
                count++;
            }

            if (count == 0) break;  

            Node* start = prev->next;
            Node* next = end->next;

            reverse(start, next);   

            prev->next = end;      
            start->next = next;     

            prev = start;          

            if (count < k) break;    
        }

        return dummy.next;
    }
};



//old
class Solution {
  public:
    Node *reverseKGroup(Node *head, int k) {
        // code here
        if(head==NULL){
           return NULL;
       }
       //reverse  first k nodes
       int count=0;
       Node*curr=head;
       Node*prev=NULL;
       Node*next=NULL;
      
       while(curr!=NULL && count<k){
           next=curr->next;
           curr->next=prev;
           prev=curr;
           curr=next;
           count++;
       }
       
       //recursion aageka dekhlega
       if(next!=NULL)
       {
           head->next = reverseKGroup(next, k);
       }
       
       return prev;
    }
};
