class Solution{
    public:
    Node* deleteMid(Node* head)
    {
        // Your Code Here
        if (head == NULL || head.next == NULL)
            return NULL;
        
        Node* fast=head, *slow=head, *prev=NULL;
        while(fast && fast->next){
            fast=fast->next->next;
            prev=slow;
            slow=slow->next;
        }
        
        prev->next=slow->next;
        return head;
    }
};
