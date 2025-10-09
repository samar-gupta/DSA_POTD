//Approach-1 : (Iterative) first building Right-Left-Element to get LRE by reversing RLE.
class Solution {
  public:
    vector<int> postOrder(Node* root) {
        // code here
        stack<Node*> st;    
        st.push(root);    
        vector<int> ans;
    
        while(!st.empty()){
            Node *curr = st.top();
            st.pop();
        
            ans.push_back(curr->data);
        
            if(curr->left){
                st.push(curr->left);
            }
        
            if(curr->right){
                st.push(curr->right);
            }
        }
    
        reverse(ans.begin(), ans.end());
        return ans;
    }
};


//Approach-2 : (Recursive)
class Solution {
  public:
    void helper(Node* node, vector<int> &result ) {
        if ( !node ) return;
        helper( node->left, result );
        helper( node->right, result );
        result.push_back( node->data );
    }
    
    vector<int> postOrder(Node* root) {
        // code here
        vector< int > result;
        helper( root, result );
        return result;
    }
};
