//Approach-1 : (Using Map)
class Solution {
  public:
    Node *cloneLinkedList(Node *head) {
        // Write your code here
        if (head == nullptr) return nullptr;

        // Map to store the mapping of original nodes to their corresponding cloned nodes
        unordered_map<Node*, Node*> nodeMapping;
        
        // Dummy node to start building the cloned list
        Node* dummyNode = new Node(0);
        Node* currentOriginalNode = head;
        Node* currentClonedNode = dummyNode;
        
        // Step 1: Create a clone of the linked list with only next pointers
        while (head != nullptr) {
            Node* clonedNode = new Node(head->data);
            currentClonedNode->next = clonedNode;
            nodeMapping[head] = clonedNode;
            currentClonedNode = clonedNode;
            head = head->next;
        }
        
        // Step 2: Update the random pointers in the cloned list
        Node* clonedHead = dummyNode->next; // Head of the cloned list
        while (currentOriginalNode != nullptr) {
            if (currentOriginalNode->random != nullptr) {
                clonedHead->random = nodeMapping[currentOriginalNode->random];
            }
            clonedHead = clonedHead->next;
            currentOriginalNode = currentOriginalNode->next;
        }
        
        return dummyNode->next;
    }
};


//Approach-2 : (without using map) (1->1->2->2->3->3)
class Solution {
  public:
    Node *cloneLinkedList(Node *head) {
        // Write your code here
        if(head == NULL)
            return NULL;
        
        Node* curr = head;
        while(curr!=NULL){
            Node* copy = new Node(curr->data);
            copy->next = curr->next;
            curr->next = copy;
            curr = copy->next;
        }
        curr = head;
        while(curr!=NULL){
            if(curr->random!=NULL){
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }
        curr = head;
        Node* copyH = head->next;
        while(curr!=NULL){
            Node* copy = curr->next;
            curr->next = copy->next;
            if(copy->next!=NULL){
                copy->next = copy->next->next;
            }
            curr= curr->next;
        }
        return copyH;
    }
};
