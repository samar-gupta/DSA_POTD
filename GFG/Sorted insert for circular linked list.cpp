// 3 cases
//1). head is NULL
//2). head->data > data
//3). IN-BETWEEN

class Solution
{
    public:
    Node *sortedInsert(Node* head, int data)
    {
       Node *nn = new Node(data);                              //1). head is NULL      //nn - newNode
       if(head == NULL) {
           nn -> next = nn;
           return nn;
       }
       
       if(head->data >= data) {                                 //2). head->data > data
           nn->next = head;
           Node* temp = head;
           while(temp->next != head) temp = temp->next;
           temp->next = nn;
           return nn;
       }
       
       Node* temp = head;                                        //3). IN-BETWEEN
       while(temp->next != head && temp->next->data < data)
       {
           temp = temp->next;
       }
       nn->next = temp->next;
       temp->next = nn;
       return head;
    }
};
