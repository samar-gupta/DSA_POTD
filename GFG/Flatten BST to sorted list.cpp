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
