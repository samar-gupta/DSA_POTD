class Solution {
    public:
    
    Node*createnode(int data) {
        Node*newnode = new Node(data);
        newnode->data = data;
        newnode->left = NULL;
        newnode->right = NULL;
        return newnode;
    }
    
    void inorderTraversal(Node*root, vector<int>&arr) {
        if(root == NULL) {
            return;
        }
        
        inorderTraversal(root->left, arr);
        arr.push_back(root->data);
        inorderTraversal(root->right, arr);
    }
    
    Node*buildHelper(vector<int>&arr, int start, int end) {
        if(start > end) {
            return NULL;
        }
        
        int mid = (start + end)/2;
        Node*root = createnode(arr[mid]);
        root->left = buildHelper(arr, start, mid-1);
        root->right = buildHelper(arr, mid+1, end);
        return root;
    }
    
    Node* buildBalancedTree(Node* root)
    {
    	vector<int> arr;
    	inorderTraversal(root, arr);
    	return buildHelper(arr, 0, arr.size()-1);            // function should return root of the modified BST
    }
};
