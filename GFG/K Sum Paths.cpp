//Approach : (PREFIX SUM || UNORDERED MAP)
//T.C : O(N) 
//S.C : O(H) 
class Solution {
  public:
    void solve(Node* root,int& ans,int& sum,int k,unordered_map<int,int>& mp)
    {
        //base case
        if(!root)
        return ;
        
        //small calculation
        //recursive calls
        sum+=root->data;
        if(mp.count(sum-k))
        ans+=mp[sum-k];
        
        if(sum==k)
        ans++;
        
        mp[sum]++;
        solve(root->left,ans,sum,k,mp);
        solve(root->right,ans,sum,k,mp);
        mp[sum]--;
        sum-=root->data;
        
    }
    
    int sumK(Node *root, int k) {
        // code here
        unordered_map<int,int> mp;
        int sum=0;
        int ans=0;
        solve(root,ans,sum,k,mp);
        return ans;
    }
};
