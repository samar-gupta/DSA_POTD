//Approach-1 : 
/*
Introduction :
   Distributing candies in a binary tree involves finding an optimal way to balance the number of candies at each node.
   In this problem, we are given a binary tree where each node contains a certain number of candies.
   The objective is to determine the minimum number of moves needed to ensure that every node has exactly one candy.
   The challenge lies in making efficient moves between adjacent nodes.

Intuition :
   To distribute candies optimally, we need to balance the number of candies at each node.
   The intuition behind the solution is to perform a bottom-up traversal of the binary tree, calculating the excess or deficit of candies at each node.
   By iteratively redistributing candies from parent to child or vice versa, we can ensure that each node eventually has precisely one candy.

Approach :
   We can implement a recursive solution to traverse the binary tree and redistribute candies.
   The distributeCandy method initializes a counter for total moves and calls a helper function distribute_helper to perform the actual candy distribution. 
   The base case checks if the current node is None, and in each recursive step, the method calculates the moves required for the current node.
*/
//T.C : O(N), where N is the number of nodes in the binary tree. The algorithm visits each node once during the traversal.
//S.C : O(H), where H is the height of the binary tree. This space is required for the recursive call stack.
class Solution {
  public:
    int distribute_helper(Node* root,int& num_moves)
    {
        if(!root)
        return 0;
        
        int left=distribute_helper(root->left,num_moves);
        int right=distribute_helper(root->right,num_moves);
        
        num_moves+=abs(left)+abs(right);
        
        return root->data+left+right-1;
    }
    
    int distCandy(Node* root) {
        // code here
        int num_moves=0;
        int call=distribute_helper(root,num_moves);
        return num_moves;
    }
};
