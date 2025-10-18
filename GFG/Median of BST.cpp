//Approach-1 : 
class Solution {
  public:
    void solve(Node* root, vector<int>& arr) {
        if(!root) return;
        solve(root->left, arr);
        arr.push_back(root->data);
        solve(root->right, arr);
    }
    
    int findMedian(Node* root) {
        // Code here
        vector<int> arr;
        solve(root, arr);
        int n = arr.size();
        if (n%2) {
            return arr[(n+1)/2 - 1];
        }
        else return arr[n/2 - 1];
    }
};
