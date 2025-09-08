//Approach-1 : 
//T.C : O(nlogn)
//S.C : O(logn) //recursion stack space, If converted to an iterative version, space complexity can be reduced further to O(1)
class Solution {
  public:
    Node* merge(Node* head1,Node* head2){
        Node* dummy=new Node(-1);
        Node* temp=dummy;
        
        while(head1 && head2){
            int val1=head1->data,val2=head2->data;
            if(val1>val2){
                temp->next=head2;
                head2=head2->next;
            } else {
                temp->next=head1;
                head1=head1->next;
            }
            
            temp=temp->next;
        }
        
        if(head1) temp->next=head1;
        else if(head2) temp->next=head2;
        
        return dummy=dummy->next;
    }
  
    Node* secondHead(Node* head){
        Node* slow=head,*fast=head;
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        return slow;
    }
  
    Node* merge_sort(Node* head){
        if(!head) return head;
        if(head->next==NULL) return head;
        
        Node* start=head;
        Node* temp=secondHead(head);
        
        Node* middle=temp->next;
        temp->next=NULL;
        
        Node* head1=merge_sort(start);
        Node* head2=merge_sort(middle);
        
        return merge(head1,head2);
    }
    
    Node* mergeSort(Node* head) {
        // code here
        return merge_sort(head);
    }
};


//Approach-2 : (Using priority queue)
//T.C : O(nlogn)
//S C : O(n)
class Solution {
  public:
    Node* mergeSort(Node* head) {
        // code here
        priority_queue<int,vector<int>,greater<int>> pq;
        Node* curr = head;
        
        while(curr) {
            pq.push(curr->data);
            curr = curr->next;
        }
        Node* ans = new Node(-1);
        curr = ans;
        
        while(!pq.empty()) {
            curr->next = new Node(pq.top());
            pq.pop();
            curr = curr->next;
        }
        
        return ans->next;
    }
};
