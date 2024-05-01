class Solution {
  public:
    // task is to complete this function
    // function should return head to the list after making
    // necessary arrangements
    struct Node* arrangeCV(Node* head) {
        // Code here
        if(!head or !head->next)
        return head;
        
        vector<char>vow,conso;
        
        Node*curr=head;
        while(curr)
        {
            if(curr->data=='a' or curr->data=='e' or curr->data=='i' or curr->data=='o' or curr->data=='u')
            vow.push_back(curr->data);
            
            else
            conso.push_back(curr->data);
            
            curr=curr->next;
        }
        curr=head;
        
        for(auto &x:vow)
        {
            curr->data=x;
            curr=curr->next;
        }
        for(auto &x:conso)
        {
            curr->data=x;
            curr=curr->next;
        }
        
        return head;
    }
};
