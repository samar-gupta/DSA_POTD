//Approach-1 : 
//T.C : O(n)
//S.C : O(1)    //only variables are used
class Solution {
  public:
    Node *first, *middle, *last, *prev;
    
    void inorder(Node* root) {
        if (!root) return;

        // Left subtree
        inorder(root->left);

        // Detect misplaced nodes
        if (prev && prev->data > root->data) {
            if (!first) {
                first = prev;
                middle = root; // First violation
            } else {
                last = root; // Second violation
            }
        }
        prev = root; // Update prev node

        // Right subtree
        inorder(root->right);
    }
    
    void correctBST(Node* root) {
        // add code here.
        first = middle = last = NULL;
        prev = new Node(INT_MIN);  // Initialize previous node with minimum value
        
        inorder(root);

        // If two nodes are not adjacent
        if (first && last) {
            swap(first->data, last->data);
        }
        // If two nodes are adjacent
        else if (first && middle) {
            swap(first->data, middle->data);
        }

    }
};


//Approach : 
class Solution {
  public:
    Node* first, *second, *prev; 
    
    void traverse(Node* root){
        if(!root)return;
        traverse(root->left);
        if(prev && (root->data < prev->data)){
            if(!first){
                first = prev; second = root;
            }
            else second = root;
        }
        prev = root;
        traverse(root->right);
    }
    
    void correctBST(Node* root) {
        // add code here.
        first=NULL, second=NULL, prev=NULL;
        traverse(root);
        swap(first->data, second->data);
    }
};
