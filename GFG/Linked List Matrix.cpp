class Solution {
  public:
  
    // Method to construct a linked list from a 2D array
    Node* solve(vector<vector<int>>& arr, int i, int j, int m) {
        if (i >= m || j >= m) return NULL;

        // Create a new node with data from the 2D array
        Node* temp = new Node(arr[i][j]);

        // Recursively construct the right and down pointers
        temp->right = solve(arr, i, j + 1, m);
        temp->down = solve(arr, i + 1, j, m);

        // Return the constructed node
        return temp;
    }
        
    // Function to construct the linked list from a 2D array    
    Node* constructLinkedMatrix(vector<vector<int>>& arr) {
        // code Here
        int m = arr.size();
        
        return solve(arr, 0, 0, m);
    }
};
