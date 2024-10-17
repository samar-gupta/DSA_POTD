class Solution {
  public:
    // Function to split a linked list into two lists alternately
    vector<Node*> alternatingSplitList(struct Node* head) {
        // Your code here
        Node* root1=new Node(-1);
        Node* curr1=root1;
        Node* root2=new Node(-1);
        Node* curr2=root2;
        int i=0;
        while(head){
            if(i%2==0)
            curr1->next=new Node(head->data),curr1=curr1->next;
            else
            curr2->next=new Node(head->data),curr2=curr2->next;
            head=head->next;
            i++;
        }
        return {root1->next,root2->next};
    }
};
