class Solution {
  public:
    // function to sort a k sorted doubly linked list
    DLLNode *sortAKSortedDLL(DLLNode *head, int k) {
        // code here
        priority_queue < int, vector<int>, greater<int> > pq;
        
        DLLNode *temp=head;
        DLLNode *curr =head;
        
        while(temp!=NULL)
        {
            pq.push(temp->data);
            if(pq.size()>k)
            {
                curr->data=pq.top();
                pq.pop();
                curr=curr->next;
            }
            temp=temp->next;
        }
        
        while(!pq.empty())
        {
            curr->data=pq.top();
            pq.pop();
            curr=curr->next;
        }
        
        return head;
    }
};
