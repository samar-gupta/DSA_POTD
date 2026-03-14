class Solution {
  public:
    vector<int> topView(Node *root) {
        // code here
        vector<int>ans;
		    if(root == NULL)
		    {
          return ans;
		    }
	    	map<int, int>mp;
		
	    	queue<pair<Node*, int>>q;
	    	q.push({root, 0});
		
	    	while(!q.empty()){
          auto it = q.front();
	    		q.pop();
    			Node* node = it.first;
	    		int level = it.second;
			
	    		if(mp.find(level) == mp.end())
	     		{
            mp[level] = node->data;
		    	}
	    		if(node->left != NULL)
		    	{
			      q.push({node->left, level-1});
		    	}
		    	if(node->right != NULL)
		     	{
            q.push({node->right, level+1});
			    }
        }
		
	    	for(auto it: mp){
		  	    ans.push_back(it.second);
	    	}
	    	return ans;
    }
};
