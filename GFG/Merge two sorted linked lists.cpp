class Solution {
  public:
    Node* sortedMerge(Node* head1, Node* head2) {
        // code here
        if(head1 == NULL && head2 != NULL) return head2;
        if(head2 == NULL && head1 != NULL) return head1;
        if(head1 == NULL && head2 == NULL) return NULL;
        
        if(head1->data < head2->data) {
            head1->next = sortedMerge(head1->next, head2);
            return head1;
        }
        else{
            head2->next = sortedMerge(head1, head2->next);
            return head2;
        }
    }
};
