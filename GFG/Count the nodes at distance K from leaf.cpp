//Approach-1 (Storing all root-to-leaf paths)
//T.C : O(n)
//S.C : O(n/2 * h) ~ O(n*h)     //h -> height of the tree   //For given n nodes, we can have a maximum of n/2 leaf nodes  {and each path from root to leaf may have a length of up to n}
class Solution
{
    public:
    vector<vector<Node*>> paths;
    
    void solve(Node* root, vector<Node*>& temp) {
        if(!root) return;
        
        temp.push_back(root);
        
        if(!root->left && !root->right) {
            paths.push_back(temp);
        }
        
        solve(root->left, temp);
        solve(root->right, temp);
        
        temp.pop_back();
    }
    
    //Function to return count of nodes at a given distance from leaf nodes.
    int printKDistantfromLeaf(Node* root, int k)
    {
    	vector<Node*> temp;
    	solve(root, temp);
    	
    	unordered_set<Node*> result;
    	
    	for(vector<Node*> &path : paths) {
    	    int n = path.size();
    	    if(n > k) {
    	        result.insert(path[n-k-1]);
    	    }
    	}
    	
    	return result.size();
    }
};





//Approach-2 (Without storing all root-to-leaf paths)  //by calculating at that path through index
//T.C : O(n)
//S.C : O(n)
class Solution
{
    public:
    
    void solve(Node* root, int idx, unordered_set<Node*>& result, vector<Node*>& temp, int k) {
        if(!root) return;
        
        temp.push_back(root);
        
        if(!root->left && !root->right) {
            if(idx - k >= 0) {
                result.insert(temp[idx-k]);
            }
        }
        
        solve(root->left, idx+1, result, temp, k);
        solve(root->right, idx+1, result, temp, k);
        
        temp.pop_back();
    }
    
    //Function to return count of nodes at a given distance from leaf nodes.
    int printKDistantfromLeaf(Node* root, int k)
    {
    	vector<Node*> temp;
    	unordered_set<Node*> result;
    	
    	solve(root, 0, result, temp, k);
    	
    	return result.size();
    }
};
