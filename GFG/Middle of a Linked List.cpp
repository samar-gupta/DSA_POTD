//Approach-1 :
class Solution {
  public:
    /* Should return data of middle node. If linked list is empty, then -1 */
    int getMiddle(Node* head) {
        // code here
        int len=0;
        Node* temp=head;
        while(temp!=NULL){
            len++;
            temp=temp->next;
        }

        temp=head;
        int mid=len/2;
        
        int count=0;
        while(count!=mid){
            temp=temp->next;
            count++;
        }
        
        return temp->data;
    }
};


//Approach-2 :
class Solution {
  public:
    /* Should return data of middle node. If linked list is empty, then -1 */
    int getMiddle(Node* head) {
        // code here
        Node* slow = head;
        Node* fast = head;

        // Move fast by two steps and slow by one step
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Slow pointer will now be pointing to the middle
        return slow->data;
    }
};
