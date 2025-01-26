class Solution {
  public:
    // Function to remove a loop in the linked list.
    void removeLoop(Node* head) {
        // code here
        if(!head->next) return ; 
             if(!head->next->next) return; 
        Node* slow = head->next; 
        Node* fast = slow->next; 
        
        while(fast&& fast->next){
          slow = slow->next; 
            fast =fast->next->next; 

            if(slow==fast){
                slow = head; 
                
                if(slow==fast){
                    while(fast->next != slow){
                        fast = fast->next; 
                    }
                }else{
                     while(slow->next!= fast->next){
                    slow = slow->next; 
                    fast = fast->next; 
                }
                
                }
               
                   fast->next = NULL; 
            }
        }
    }
};
