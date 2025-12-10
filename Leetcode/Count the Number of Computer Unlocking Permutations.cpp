//Leetcode Link : https://leetcode.com/problems/count-the-number-of-computer-unlocking-permutations

//Approach - Simple observation and maths factorial
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int M = 1e9+7;

    int countPermutations(vector<int>& complexity) {
        int n = complexity.size();

        long long result = 1;

        for(int i = 1; i < n; i++) {
            if(complexity[i] <= complexity[0])
                return 0;
            
            result = (result * i) % M;
        }
        
        return result;
    }
};
