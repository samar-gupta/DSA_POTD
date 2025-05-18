class Solution {
  public:
    vector<int> findSpiral(Node* root) {
        // code here
        vector<int> v;
    int level=0;
    if(root==NULL){
        return v;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int size=q.size(); 
        vector<int> temp;
        for(int i=0;i<size;i++){
            Node* r=q.front();
            q.pop();
            temp.push_back(r->data);
            if(r->left){
                q.push(r->left);
            }
            if(r->right){
                q.push(r->right);
            }
        }
        if(level%2==0){
            reverse(temp.begin(),temp.end());
        }
        for(int i=0;i<temp.size();i++){
            v.push_back(temp[i]);
        }
        level++;
    }
    return v;
    }
};
