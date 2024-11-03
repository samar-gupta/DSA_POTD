//Approach-1 : 
class Solution {
  public:
    bool isLengthEven(struct Node **head) {
        // Code here
        Node* current = *head;
        int count=0;
        while(current!=NULL){
            count++;
            current= current->next;
            
        }
        return count%2==0;
    }
};


//Approach-2 : 
class Solution {
  public:
    bool isLengthEven(struct Node **head) {
        // Code here
        Node* fast =* head;
        
        // Fast pointer moves two steps at a time
        while (fast && fast->next) {
            fast = fast->next->next;
        }
        
        // If fast ends up at NULL, the length is even; otherwise, it's odd
        return fast == NULL;
    }
};
