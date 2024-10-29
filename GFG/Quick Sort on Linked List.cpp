//Approach-1
// Solution class with quickSort function
class Solution {
  public:
    struct Node* quickSort(struct Node* head) {
        // code here
        if(head==NULL || head->next==NULL){
            return head;
        }
        struct Node*tail= getTail(head);
        solveSort(head,tail);
        return head;
    }    
    
    void solveSort(struct Node*head,struct Node*tail){
        if(head==NULL || head==tail)  return;
        struct Node*pivot=partition(head,tail);
        solveSort(head,pivot);
        solveSort(pivot->next,tail);
    }
        
    struct Node*partition(struct Node*head,struct Node*tail){
        struct Node *cur=head->next;
        struct Node *pivot=head;
        struct Node*prev=head;
        while(cur!=tail->next){
            if(pivot->data > cur->data){
                swap(prev->next->data,cur->data);
                prev=prev->next;
            }
            cur=cur->next;
        }
        swap(prev->data,pivot->data);
        return prev;
    }
        
    struct Node* getTail(struct Node*head){
        struct Node*cur=head;
        while(cur!=NULL && cur->next!=NULL){
            cur=cur->next;
        }
        
        return cur;
    }
};



//Approach-2
struct node* parti(struct node* head,struct node* tail){
    struct node* pvt = head, *curr = head->next, *prev= head;
    while(curr!=tail->next){
        if(pvt->data > curr->data){
            swap(prev->next->data,curr->data);
            prev = prev->next;
        }
        curr = curr->next;
    }
    swap(pvt->data,prev->data);
    return prev;
}
void solve(struct node* head,struct node* tail){
    if(!head || !tail || head==tail) return;
    struct node* pvt = parti(head,tail);
    solve(head,pvt);
    solve(pvt->next,tail);
}
void quickSort(struct node **head) {
    //  if(!head || !head->next) return NULL;
    struct node* tail = *head;
    while(tail->next)
        tail = tail->next;
    solve(*head,tail);
}
