class Solution {
  public:
    int ans=INT_MIN,maxlevel=0;
    void traverse(Node* r,int level,int sum){
        if(r==NULL) return;
        sum+=r->data;
        if(level>maxlevel){
            ans=sum;
            maxlevel=level;
        }
        else if(level==maxlevel){
            ans=max(ans,sum);
        }
        traverse(r->left,level+1,sum);
        traverse(r->right,level+1,sum);
    }
    
    int sumOfLongRootToLeafPath(Node *root) {
        // code here
        traverse(root,1,0);
        return ans;
    }
};
