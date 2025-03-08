//Leetcode Link : https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks

//Approach-1 (Brute Force)
//T.C : O(n*k)
//S.C : O(1)
class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int result = k;

        for (int i = 0; i <= n - k; i++) {
            int W = 0;
            for (int j = i; j-i+1 <= k; j++) {
                if (blocks[j] == 'W') {
                    W++;
                }
            }
            result = min(result, W);
        }

        return result;
    }
};


//Approach-2 (Sliding Window)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int i = 0;
        int j = 0;

        int ops = k;
        int W = 0;

        while(j < n) {
            if(blocks[j] == 'W') {
                W++;
            }

            if(j - i + 1 == k) {
                ops = min(ops, W);

                if(blocks[i] == 'W') {
                    W--;
                }
                i++;
            }
            j++;
        }

        return ops;
    }
};
