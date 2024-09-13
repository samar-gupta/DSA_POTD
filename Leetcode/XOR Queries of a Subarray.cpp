//Leetcode Link : https://leetcode.com/problems/xor-queries-of-a-subarray

//Approach (Simple XOR Property & Cumulative Xor)
//T.C : O(n+q)
//S.C : O(n)
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();

        vector<int> cumXor(n, 0); //space : O(n)

        cumXor[0] = arr[0];
        for(int i = 1; i < n; i++) { //O(n)
            cumXor[i] = cumXor[i-1] ^ arr[i];
        }

        vector<int> result;
        for(vector<int>& query : queries) { //O(q)
            int L = query[0];
            int R = query[1];

            int xor_val = cumXor[R] ^ (L == 0 ? 0 : cumXor[L-1]);

            result.push_back(xor_val);
        }

        return result;
    }
};
