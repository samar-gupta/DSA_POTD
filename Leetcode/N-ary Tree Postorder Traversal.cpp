//Leetcode Link : https://leetcode.com/problems/n-ary-tree-postorder-traversal/

//Approach : (Simple Recursion)
class Solution {
public:
    vector<int> result;
    
    void traverse(Node* root) {
        if(!root)
            return;
        for(Node*& x: root->children) {
            traverse(x);
        }
        result.push_back(root->val);
    }
    
    vector<int> postorder(Node* root) {
        result.clear();
        traverse(root);
        return result;
    }
};
