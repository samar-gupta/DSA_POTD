class Solution {
  public:
    /*Structure of the node of the linled list is as

    struct Node {
        int data;
        struct Node* next;

        Node(int x){
            data = x;
            next = NULL;
        }
    };
    */
    // your task is to complete this function
    // function should return sum of last n nodes
    int sumOfLastN_Nodes(struct Node* head, int n) {
        // Code here
        int totalNodes = 0;
        Node* current = head;
        
        while(current != NULL){
            current = current->next;
            totalNodes++;
        }
        
        int target = totalNodes - n;
        current = head;
        
        while(target > 0){
            current = current->next;
            target--;
        }
        
        int sum = 0;
        
        while(current != NULL){
            sum += current->data;
            current = current->next;
        }
        
        return sum;
    }
};
