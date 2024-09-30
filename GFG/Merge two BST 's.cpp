//Approach-1 : 
class Solution {
  public:
    // Function to return a list of integers denoting the node
    // values of both the BST in a sorted order.
    void inorder(Node* root, vector<int>&ans){
        if(root==NULL) return;
        
        inorder(root->left, ans);
        ans.push_back(root->data);
        inorder(root->right, ans);
        
        return;
    }
    
    vector<int> merge(Node *root1, Node *root2) {
        // Your code here
        vector<int>arr1, arr2, ans;
        inorder(root1, arr1);
        inorder(root2, arr2);
        
        int i=0, j=0;
        while(i<arr1.size() && j<arr2.size()){
            if(arr1[i]<=arr2[j]){
                ans.push_back(arr1[i++]);
            }
            else{
                ans.push_back(arr2[j++]);
            }
        }
        while(i<arr1.size()){
            ans.push_back(arr1[i++]);
        }
        while(j<arr2.size()){
            ans.push_back(arr2[j++]);
        }
        return ans;
    }
};



//Approach-2 : 
class Solution
{
    public:
    //Function to return a list of integers denoting the node 
    //values of both the BST in a sorted order.
    void inorder(vector<int> &v,Node* root){
        if(!root) return;
        inorder(v,root->left);
        v.push_back(root->data);
        inorder(v,root->right);
    }
    vector<int> merge(Node *root1, Node *root2)
    {
       vector<int> v1,v2;
       inorder(v1,root1);
       inorder(v2,root2);
       int i = 0;
       int j =0;
       int N = v1.size();
       int M = v2.size();
       vector<int> answer;
       
       while(i<N && j<M) {
           if(v1[i] < v2[j])
               answer.push_back(v1[i++]);
           else if(v1[i] > v2[j])
               answer.push_back(v2[j++]);
           else if(v1[i] == v2[j])
               answer.push_back(v1[i++]);

       }
       while(i<N)
           answer.push_back(v1[i++]);
       while(j<M)
           answer.push_back(v2[j++]);
     return answer;
    }
};
