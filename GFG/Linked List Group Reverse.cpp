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
