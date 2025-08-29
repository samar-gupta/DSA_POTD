//Leetcode Link : https://leetcode.com/problems/alice-and-bob-playing-flower-game

//Approach - Using simple maths
//T.C : O(1)
//S.C : O(1)
class Solution {
public:
    long long flowerGame(int n, int m) {
        return 1LL * ((n+1)/2) * (m/2) + 1LL * (n/2) * ((m+1)/2);
    }
};
