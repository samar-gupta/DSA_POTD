//Approach-1
//T.C : O(n)
//S.C : AUxiliary Space is O(1) and Stack Space due to recursion is O(n)
class Solution
{
public:
    Node *flattenBST(Node *root) {
        if(!root) {
            return NULL;
        }
        
        Node* head   = flattenBST(root->left);
        root->left = NULL;
        root->right  = flattenBST(root->right);
        
        if (head) {
            Node *temp = head;
            while (temp->right) {
                temp = temp->right;
            }
            temp->right = root;
        } else {
            // If head is NULL, root becomes the head
            head = root;
        }
        
        return head;
    }
};




//Approach-2
class Solution
{
public:
    Node *flattenBST(Node *root)
    {
        Node *head = newNode(0);
        inorder(root, head);
        return head->right;
    }
    
    Node *inorder(Node *root, Node *head)
    {
        if (root == NULL)
            return head;
            
        head = inorder(root->left, head);
        head->right = newNode(root->data);
        head = head->right;
        head = inorder(root->right, head);
        return head;
    }
};
