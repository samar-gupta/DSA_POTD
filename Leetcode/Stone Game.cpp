//Company Tags  : Google, Adobe, Amazon, Microsoft
//Leetcode Link : https://leetcode.com/problems/stone-game/

//Approach-1 (Recur+Memo) O(n^2) - Standard Optimal Game Strategy Concept
//T.C : O(n^2)
//S.C : O(n^2)
class Solution {
public:
    int n;
    int t[501][501];
    int solve(vector<int>& piles, int i, int j) {
        if(i > j)
            return 0;
        
        if(t[i][j] != -1)
            return t[i][j];
        
        /*
            That's how optimal game strategy works. Expect your opponent to be playing optimally
            -When it's your turn, do your best
            -When it's your opponent's turn, expect the worst (that's why min() is taken below)
        */
        int choose_i  = piles[i]  + min(solve(piles, i+2, j), solve(piles, i+1, j-1));
        int choose_j = piles[j] + min(solve(piles, i, j-2), solve(piles, i+1, j-1));
        
        return t[i][j] = max(choose_i, choose_j);
    }
    bool stoneGame(vector<int>& piles) {
        n = piles.size();
        memset(t, -1, sizeof(t));
        int sum = accumulate(begin(piles), end(piles), 0);
        int alexScore = solve(piles, 0, n-1);
        
        return alexScore > sum/2;
    }
};


//Approach-2 (Constant Time)
//T.C : O(1)
//S.C : O(1)
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        return true;
    }
};
