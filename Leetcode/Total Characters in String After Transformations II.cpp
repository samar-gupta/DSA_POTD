//Leetcode Link : https://leetcode.com/classic/problems/total-characters-in-string-after-transformations-ii/description/

//Approach : https://leetcode.com/problems/total-characters-in-string-after-transformations-ii/solutions/6742692/complete-walkthrough-matrix-exponentiation-optimized-c-py3-java-js
class Solution {
public:
    int MOD = 1e9 + 7;

    typedef vector<vector<long long>> Matrix;

    Matrix multiply(const Matrix& a, const Matrix& b) {
        Matrix res(26, vector<long long>(26, 0));
        for (int i = 0; i < 26; ++i) {
            for (int k = 0; k < 26; ++k) {
                if (a[i][k] == 0) continue;
                for (int j = 0; j < 26; ++j) {
                    res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % MOD;
                }
            }
        }
        return res;
    }

    Matrix matrix_pow(Matrix mat, int power) {
       Matrix result(26, vector<long long>(26, 0));
       for (int i = 0; i < 26; ++i) {
           result[i][i] = 1; // Identity matrix
       }
        while (power > 0) {
            if (power % 2 == 1) {
                result = multiply(result, mat);
            }
            mat = multiply(mat, mat);
            power /= 2;
        }
        return result;
    }
    
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        // Initialize the transition matrix
        Matrix transition(26, vector<long long>(26, 0));
        for (int c = 0; c < 26; ++c) {
            int num = nums[c];
            for (int j = 1; j <= num; ++j) {
                int next_char = (c + j) % 26;
                transition[c][next_char]++;
            }
        }
        
        // Raise the transition matrix to the t-th power
        Matrix mat_pow = matrix_pow(transition, t);
        
        // Initialize the initial count vector
        vector<long long> cnt(26, 0);
        for (char c : s) {
            cnt[c - 'a']++;
        }
        
        // Multiply the count vector by the matrix^t to get the new counts
        vector<long long> new_cnt(26, 0);
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                new_cnt[j] = (new_cnt[j] + cnt[i] * mat_pow[i][j]) % MOD;
            }
        }
        
        // Sum all the counts to get the total length
        long long total = 0;
        for (long long x : new_cnt) {
            total = (total + x) % MOD;
        }
        return total;
    }
};
