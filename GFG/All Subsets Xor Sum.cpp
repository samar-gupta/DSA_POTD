//Approach-1 : (Recursion + Memorization)
class Solution {
  public:
    int helper(int i, int t, int n, vector<int> &arr, vector<vector<int>> &dp){
      if(i==n){
        return t;
      }
      
      if(dp[i][t] != -1)
        return dp[i][t];
      
      //take
      int take = helper(i+1, t^arr[i], n, arr, dp);
      //not-take
      int notTake = helper(i+1, t, n, arr, dp);
      
      
      return dp[i][t] = (take+notTake);
    }
    
    int subsetXORSum(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int>(2e3+1, -1));
        return helper(0, 0, n, arr, dp);
    }
};


//Approach-2 : 
/*
Intuition (C++ Solution) : 
  We need the sum of XORs of all subsets of an array.
Key insight: Each bit in the numbers contributes independently to the XOR sum.

Observation:
  If you take all subsets, every element appears in exactly half of the subsets. Why?
  For an array of size n, total subsets = 2^n.
  Fix one element, it can either be in a subset or not. So it appears in 2^(n-1) subsets.
  Therefore, the XOR of all subsets can be computed as:
    sum of XORs of all subsets=(2n−1)×(XOR of all elements)

Dry Run
Example 1:
  arr = [7, 2]
 
 XOR of all elements: 7 ^ 2 = 5
 Number of subsets each element appears in: 2^(n-1) = 2^(2-1) = 2
 Sum of XORs of all subsets: 2 * (7 | 2?)

Wait, careful! The code you shared uses OR, but the formula uses XOR, not OR. Correct approach:
  XOR of all elements = 7 ^ 2 = 5
  Multiply by 2^(n-1) = 2
  Answer = 5 * 2 = 10

Hmm, your example output is 14, so let’s check:

All subsets:
[]       -> XOR = 0
[7]      -> XOR = 7
[2]      -> XOR = 2
[7, 2]   -> XOR = 5
Sum = 0 + 7 + 2 + 5 = 14                                                       
The formula 2^(n-1) * (XOR of all elements) does work but we need to consider OR? Actually, the approach with OR works differently. The common optimized approach is indeed OR because every bit contributes in 2^(n-1) subsets:

 ans = OR of all numbers * 2^(n-1)

Check with [7, 2]:
  OR of all elements: 7 | 2 = 7
  2^(n-1) = 2^(2-1) = 2
  7 * 2 = 14 ✅ Correct

So using OR is correct for sum of XORs in all subsets.

Step-by-Step Dry Run :
  (arr = [1, 2, 3])
  n = 3 → 2^(n-1) = 4
  OR of all elements = 1 | 2 | 3 = 3
  Sum = 4 * 3 = 12 ✅ matches example


Key points:
  ans = OR of all elements → 
  val = 2^(n-1) → number of subsets where each bit contributes.gets all bits that appear in any number.
  Multiply → gives the sum of XOR of all subsets.

Time Complexity :
  Loop through array once → O(n) 
  Space: only a few variables → O(1) 

Space Complexity :
  No extra array is used → O(1) 
  
*/
class Solution {
  public:
    int subsetXORSum(vector<int>& arr) {
        // code here
        int ans=0;
        int n=arr.size();
        
        for(int i=0;i<n;i++){
            ans=ans|arr[i];
        }
        
        int val=(1<<(n-1));
        
        return (val*ans);
    }
};
