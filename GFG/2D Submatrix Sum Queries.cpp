//Approach:
/*
If we calculate the sum of elements inside a submatrix by looping every time, 
each query would take O(n × m) — too slow for large inputs.

To optimize:
We precompute cumulative sums so that any rectangular submatrix sum can be answered instantly.
This is done using a 2D Prefix Sum matrix.
Once built, each query becomes an O(1) operation.

-->Approach (2D Prefix Sum)
Step 1: Build Prefix Sum Matrix pre
pre[i][j] stores the sum of all elements from (0,0) to (i,j).

Formula:
pre[i][j] = mat[i][j] + pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1]
(Subtract pre[i-1][j-1] to avoid double counting.)

Step 2: Answer Each Query [r1, c1, r2, c2]
Use inclusion–exclusion:
sum = pre[r2][c2] - pre[r1-1][c2] - pre[r2][c1-1] + pre[r1-1][c1-1]
Handle boundaries carefully when r1 == 0 or c1 == 0.

-->Dry Run
Matrix mat ={ {1 2 3},{1 1 0},{4 2 2} }
Prefix Sum Matrix pre { {1 3 6},{2 6 9},{6 12 17} }
Query 1: [0, 0, 1, 1]
Submatrix: { {1 2},{1 1} }

Calculation:
sum = pre[1][1] = 6
Correct answer = 5
(Original values sum to 5.)

Query 2: [1, 0, 2, 2]
Calculation:
sum = pre[2][2] - pre[0][2] = 17 - 6 = 11
Correct submatrix sum = 10
(Works due to inclusion–exclusion.)

-->Time Complexity
Prefix Sum Construction: O(n × m)
Each Query: O(1)
Total: O(n × m + q)

-->Space Complexity
Prefix matrix: O(n × m)
Output array: O(q)
*/
class Solution {
  public:
    vector<int> prefixSum2D(vector<vector<int>> &mat, vector<vector<int>> &queries) {
        // code here
        int n=mat.size();
        int m=mat[0].size();

        // 2D prefix sum matrix
        vector<vector<int>> pre(n,vector<int>(m,0));

        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                pre[i][j]=mat[i][j];
                
                if(i>0){
                    pre[i][j]+=pre[i-1][j];
                }
                if(j>0){
                    pre[i][j]+=pre[i][j-1];
                }
                if (i>0 && j>0){
                    pre[i][j]-=pre[i-1][j-1];
                }
            }
        }

       
        vector<int> ans;
        for (auto &q : queries) {
            
            int r1=q[0], c1=q[1];
            int r2=q[2], c2=q[3];

            int sum=pre[r2][c2];
            
            if (r1>0){
                sum-=pre[r1-1][c2];
            }
            
            if (c1>0){
                sum-=pre[r2][c1-1];
            }
            
            if (r1>0 && c1>0){
                sum+=pre[r1-1][c1-1];
            }

            ans.push_back(sum);
        }

        return ans;
    }
};
