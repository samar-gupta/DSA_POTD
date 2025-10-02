//Approach-1 : 
class Solution {
  public:
    void solve(vector<vector<int>> &ans, int i, int n,int k,vector<int> temp){        
        if(n<0){
            return;
        }
        
        if(k==0){
            if(n==0){
                ans.push_back(temp);            
            }
            return;
        }
                
        for(int j = i+1;j<=9;j++){
            temp.push_back(j);
            solve(ans,j,n-j,k-1,temp);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(int n, int k) {
        // code here
        vector<vector<int>> ans;        
        vector<int> temp;        
        solve(ans,0,n,k,temp);
        return ans;
    }
};


//Approach-1 : 
class Solution {
  public:
    void backtrack(int start, int remainingSum, int remainingCount, 
                   vector<int>& current, vector<vector<int>>& result) {
        // Base case: if we've used exactly k numbers
        if (remainingCount == 0) {
            // Check if the sum equals n
            if (remainingSum == 0) {
                result.push_back(current);
            }
            return;
        }
        
        // Try each number from start to 9
        for (int i = start; i <= 9; i++) {
            // Early termination: if current number is too large
            if (i > remainingSum) {
                break;
            }
            
            // Choose the current number
            current.push_back(i);
            
            // Recursively try the next numbers
            backtrack(i + 1, remainingSum - i, remainingCount - 1, current, result);
            
            // Backtrack: remove the last number
            current.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(int n, int k) {
        // code here
        vector<vector<int>> result;
        vector<int> current;
        backtrack(1, n, k, current, result);
        return result;
    }
};
