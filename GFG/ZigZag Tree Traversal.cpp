//Approach-1 : 
class Solution {
  public:
    vector<int> zigZagTraversal(Node* root) {
        // code here
        int level = 1;
    	vector<int> ans;
    	queue<Node*> q;
    	q.push(root);
    	while(!q.empty()){
    	    vector<int> temp;
    	    int sz = q.size();
    	    while(sz--){
    	        temp.push_back(q.front()->data);
    	        if(q.front()->left) q.push(q.front()->left);
    	        if(q.front()->right) q.push(q.front()->right);
    	        q.pop();
    	    }
    	    if(level % 2 == 0)
    	        reverse(temp.begin(), temp.end());
	        for(int i=0; i<temp.size(); i++)
	            ans.push_back(temp[i]);
            level++;
    	}
    	return ans;
    }
};


//old
class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root) {
    	// Code here
    	vector<vector<int>>traversal;
    	queue<Node*>q;
    	q.push(root);

    	while(!q.empty()){

    	    int n=q.size();
    	    vector<int>level;

    	    for(int i=0;i<n;i++){

    	        Node* node=q.front();
    	        q.pop();

    	        level.push_back(node->data);

    	        if(node->left){
    	            q.push(node->left);
    	        }

    	        if(node->right){
    	            q.push(node->right);
    	        }

    	    }

    	    traversal.push_back(level);
    	}

    	vector<int>ans;

    	for(int i=0;i<traversal.size();i++){

    	    if(i%2==1){
    	        reverse(traversal[i].begin(), traversal[i].end());
    	    }

    	    for(auto it:traversal[i]){
    	        ans.push_back(it);
    	    }

    	}

    	return ans;
    }
};
