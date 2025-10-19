//Approach-1 :
/* Intuition
     A Binary Search Tree (BST) has an inorder traversal that produces sorted node values.
     To find the k closest values to a target:
     Traverse the BST inorder to get all values in a sorted array.
     Sort the array based on absolute difference from the target, breaking ties by smaller value.
     Take the first k elements, since they will be the closest.
     This approach is simple and works because all BST values are known and can be sorted
*/
/*Time Complexity (TC)
    Inorder Traversal.              : Visits all nodes once → O(n)
    Sorting by absolute difference  : Sorting an array of size n → O(n log n)
    Picking k elements.             : Simple loop → O(k)
    Overall                         : O(n+nlog⁡n+k)=O(nlogn)
*/
/*Space Complexity (SC)
    Inorder array ans → stores all n nodes → O(n)
    Result array res → stores k nodes → O(k)
    Recursion stack → for inorder traversal → worst-case O(h) where h = height of BST
    For a balanced BST   : O(log n)
    For skewed BST       : O(n)
    Overall              : O(n) auxiliary space
*/
class Solution {
  public:
    void inorder(Node* root, vector<int>& ans) {
        if(root==NULL){
            return;
        }
        
        inorder(root->left,ans);
        ans.push_back(root->data);
        inorder(root->right,ans);
    }
    
    vector<int> getKClosest(Node* root, int target, int k) {
        // code here
        vector<int> ans;
        inorder(root,ans);

        // Sort by absolute difference from target, break tie by smaller value
        sort(ans.begin(),ans.end(),[target](int a,int b){
            int diffA=abs(a-target);
            int diffB=abs(b-target);
            
            if(diffA==diffB){// smaller value first if tie
                return a<b;
            }  
            return diffA<diffB;
        });

        vector<int> res;
        int n=ans.size();
        for (int i=0;i<k && i<n;i++) {
            res.push_back(ans[i]);
        }

        return res;
    }
};


//Approach-2 : (Using priority_queue)
class Solution {
  public:
    void solve(Node* root, vector<int>&ans){
        if(root == NULL) return ;
        
        solve(root->left,ans);
        ans.push_back(root->data);
        solve(root->right,ans);
    }
   
    vector<int> getKClosest(Node* root, int target, int k) {
        // code here
        vector<int>ans;
        solve(root,ans);
        sort(ans.begin(),ans.end());
        int n = ans.size();
        priority_queue<int,vector<int>, greater<int>>q;
        for(int i=0; i<n; i++){
            if(q.size() < k){
                q.push(ans[i]);
            }
            else{
                int t = q.top();
                if(abs(t-target) > abs(ans[i] - target)){
                    q.pop();
                    q.push(ans[i]);
                }
            }
        }
        vector<int>res;
        while(!q.empty()){
            res.push_back(q.top());
            q.pop();
        }
        return res;
    }
};


//Approach-2 :
//T.C : O(N log N)  — each node is pushed into the heap once
//S.C : O(N) ,heap stores up to N elements
class Solution {
  public:
    // Helper function: inorder traversal + store (difference, value) pairs
    void inorder(Node* root, int target,
                 priority_queue<pair<int, int>,
                 vector<pair<int, int>>,
                 greater<pair<int, int>>>& pq)
    {
        if (!root)
            return;

        // Traverse left subtree
        inorder(root->left, target, pq);

        // Push current node's absolute difference and value
        pq.push({abs(root->data - target), root->data});

        // Traverse right subtree
        inorder(root->right, target, pq);
    }
    
    vector<int> getKClosest(Node* root, int target, int k) {
        // code here
        // Min-heap storing (difference, value)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // Fill heap via inorder traversal
        inorder(root, target, pq);

        // Extract k closest values
        vector<int> result;
        while (!pq.empty() && k--) {
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }
};
