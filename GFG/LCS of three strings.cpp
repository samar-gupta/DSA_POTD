//updated
// Approach: Top-down recursive DP with memoization. We compare last characters of the strings and recursively reduce the problem.
// Time Complexity: O(n1 * n2 * n3) since we compute each state (i, j, k) only once and memoize the result.
// Space Complexity: O(n1 * n2 * n3) for the memoization table plus O(n1 + n2 + n3) recursion stack space.
class Solution {
public:
    // Memoization table to store subproblem results
    int dp[101][101][101]; // Max length for each string is 100, so 101 for 0-based indexing

    // Recursive function to find LCS
    int solve(string& s1, string& s2, string& s3, int i, int j, int k) {
        // Base case: if any string is empty, LCS is 0
        if (i == 0 || j == 0 || k == 0) {
            return 0;
        }

        // Return already computed result
        if (dp[i][j][k] != -1) {
            return dp[i][j][k];
        }

        // If current characters match in all three strings, include in LCS
        if (s1[i - 1] == s2[j - 1] && s2[j - 1] == s3[k - 1]) {
            return dp[i][j][k] = 1 + solve(s1, s2, s3, i - 1, j - 1, k - 1);
        }

        // Else, take max by excluding one character from one of the strings
        return dp[i][j][k] = max({
            solve(s1, s2, s3, i - 1, j, k),   // Exclude from s1
            solve(s1, s2, s3, i, j - 1, k),   // Exclude from s2
            solve(s1, s2, s3, i, j, k - 1)    // Exclude from s3
        });
    }
    // Main function to call the recursive solver
    int lcsOf3(string& s1, string& s2, string& s3) {
        int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();

        // Initialize dp array with -1 to denote uncomputed states
        memset(dp, -1, sizeof(dp));

        // Start recursion with full lengths
        return solve(s1, s2, s3, n1, n2, n3);
    }
};


//old
//Approach-1 : (Recursion + Memo)
class Solution {
    public:

        int N1,N2,N3;
        int t[21][21][21];
        
        int solve(string &A,string &B,string &C,int i,int j,int k) {
            
            if(i>=N1 || j>=N2 || k>=N3){
                return 0;
            }
            
            if(t[i][j][k]!=-1){
                return t[i][j][k];
            }
            
            if(A[i]==B[j] && B[j]==C[k]){
                return t[i][j][k] = 1 + solve(A,B,C,i+1,j+1,k+1);
            }
            
            int a=solve(A,B,C,i,j+1,k);
            int b=solve(A,B,C,i+1,j,k);
            int c=solve(A,B,C,i,j,k+1);
            int d=solve(A,B,C,i+1,j+1,k);
            int e=solve(A,B,C,i,j+1,k+1);
            int f=solve(A,B,C,i+1,j,k+1);
            
            return t[i][j][k] = max(a,max(b,max(c,max(d,max(e,f)))));
        }
        
        int LCSof3 (string A, string B, string C, int n1, int n2, int n3) {
            N1=n1,N2=n2,N3=n3;
            memset(t,-1,sizeof(t));
            return solve(A,B,C,0,0,0);
        }
};





//Approach-2 : (Bottom-Up)
class Solution {
    public:

        int LCSof3 (string s1, string s2, string s3, int n1, int n2, int n3) {
            int t[n1+1][n2+1][n3+1];
            
            for(int i = 0; i < n1+1; i++) {
                for(int j = 0; j < n2+1; j++) {
                    for(int k = 0; k < n3+1; k++) {
                        
                        if(i == 0 || j == 0 || k == 0) {
                            t[i][j][k] = 0;
                        } else if(s1[i-1] == s2[j-1] && s2[j-1] == s3[k-1]) {
                            t[i][j][k] = 1 + t[i-1][j-1][k-1];
                        } else {
                            t[i][j][k] = max({t[i-1][j][k], t[i][j-1][k], t[i][j][k-1]});
                        }
             
                    }
                }
            }
            
            return t[n1][n2][n3];
        }
};
