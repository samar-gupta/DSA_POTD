//Approach-1 DFS (Using unordered_map)
class Solution {
public:

    unordered_map<Node*, Node*> mp;
    
    void DFS(Node* node, Node* clone_node) {
        
        for(Node* n : node->neighbors) {
            
            if(mp.find(n) == mp.end()) {
                
                Node* clone = new Node(n->val);
                mp[n] = clone;
                clone_node->neighbors.push_back(clone);
                
                DFS(n, clone);
                
            } else {
                clone_node->neighbors.push_back(mp[n]);
            }
            
        }
        
    }

    Node* cloneGraph(Node* node) {
        if(!node)
            return NULL;
            
        mp.clear();
            
        Node* clone_node = new Node(node->val);
        mp[node] = clone_node;
        DFS(node, clone_node);
      
        return clone_node;
    }
};
