class Solution
{
    public:

    void solve(Node* root, set<int>&s) {
        if(root == NULL) return;
        solve(root->left, s);
        s.insert(root->data);
        solve(root->right, s);
    }
    
    //Function to find the nodes that are common in both BST. 
    vector <int> findCommon(Node *root1, Node *root2)
    {
        set<int> s1, s2;
        solve(root1, s1);
        solve(root2, s2);
        
        vector<int> ans;
        for(auto i : s1) {
            if(s2.find(i) != s2.end())
                ans.push_back(i);
        }
        
        return ans;
    }
};
