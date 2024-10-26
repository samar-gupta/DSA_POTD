class Solution {
  public:
    int count(struct Node* head, int key) {
        // add your code here
        int count = 0;
        
        Node* current = head;
        
        while(current != NULL){
            if(current->data == key){
                count++;
            }
            current = current->next;
        }
        
        return count;
    }
};
