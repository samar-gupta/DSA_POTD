//Leetcode Link : https://leetcode.com/problems/number-of-paths-with-max-score/

//Approach-1 (Recursion + Memoization)
//T.C : O(n^2)
//S.C : O(n^2)
class Solution {

    int n;
    int MOD = 1e9 + 7;
    vector<vector<pair<int, int>>> t;

    int getIntFromChar(char ch) {
        return ch != 'S' ? ch - '0' : 0;
    }

    bool isValid(int i, int j, vector<string>& board) {
        return i >= 0 && i < n && j >= 0 && j < n && board[i][j] != 'X';
    }

    pair<int, int> solve(int i, int j, vector<string>& board) {
        if (board[i][j] == 'E') 
            return {0, 1};   // reached end - no more coins, but found one path that reaches end - {0, 1}
        if (board[i][j] == 'X') 
            return {0, 0};   // dead end

        if (t[i][j] != make_pair(-1, -1))
            return t[i][j];

        int upScore = 0,   upPaths = 0;
        int leftScore = 0, leftPaths = 0;
        int diagScore = 0, diagPaths = 0;
        char ch = board[i][j];

        if (isValid(i - 1, j, board)) {
            auto [score, paths] = solve(i - 1, j, board);
            upScore = score;
            upPaths = paths;
            if (upPaths > 0)
                upScore += getIntFromChar(ch);
        }
        if (isValid(i, j - 1, board)) {                 // move left
            auto [score, paths] = solve(i, j - 1, board);
            leftScore = score;
            leftPaths = paths;
            if (leftPaths > 0)
                leftScore += getIntFromChar(ch);
        }
        if (isValid(i - 1, j - 1, board)) {             // move up-left (diagonal)
            auto [score, paths] = solve(i - 1, j - 1, board);
            diagScore = score;
            diagPaths = paths;
            if (diagPaths > 0)
                diagScore += getIntFromChar(ch);
        }

        int bestScore, bestPaths;
        if (upScore == leftScore && leftScore == diagScore) {
            bestScore = upScore;
            bestPaths = upPaths + leftPaths + diagPaths;
        } else if (upScore == leftScore) {
            bestScore = upScore;
            bestPaths = upPaths + leftPaths;
            if (diagScore > bestScore || (diagScore == bestScore && diagPaths > bestPaths)) {
                bestScore = diagScore; bestPaths = diagPaths;
            }
        } else if (leftScore == diagScore) {
            bestScore = leftScore;
            bestPaths = leftPaths + diagPaths;
            if (upScore > bestScore || (upScore == bestScore && upPaths > bestPaths)) {
                bestScore = upScore; bestPaths = upPaths;
            }
        } else {
            bestScore = upScore; bestPaths = upPaths;
            if (leftScore > bestScore || (leftScore == bestScore && leftPaths > bestPaths)) {
                bestScore = leftScore; bestPaths = leftPaths;
            }
            if (diagScore > bestScore || (diagScore == bestScore && diagPaths > bestPaths)) {
                bestScore = diagScore; bestPaths = diagPaths;
            }
        }

        t[i][j] = {bestScore, bestPaths % MOD};
        return t[i][j];
    }

public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        n = board.size();
        
        t.assign(n, vector<pair<int, int>>(n, {-1, -1}));

        auto result = solve(n - 1, n - 1, board);
        return {result.first, result.second};
    }
};


//Approach-2 (Bottom Up)
//T.C : O(n^2)
//S.C : O(n^2)
class Solution {
    int n;
    int MOD = 1e9 + 7;
    vector<vector<pair<int, int>>> t;

    int getIntFromChar(char ch) {
        return ch != 'S' ? ch - '0' : 0;
    }
    bool isValid(int i, int j, vector<string>& board) {
        return i >= 0 && i < n && j >= 0 && j < n && board[i][j] != 'X';
    }

public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        n = board.size();

        t.assign(n, vector<pair<int, int>>(n, {0, 0}));
        // t[i][j] = {best score, count of paths} to reach E from (i,j)

        // Base case
        t[0][0] = {0, 1};

        // Predecessors are up/left/up-left, so fill i,j INCREASING.
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {

                if (board[i][j] == 'E') 
                    continue;
                if (board[i][j] == 'X') 
                    continue;

                int upScore = 0,   upPaths = 0;
                int leftScore = 0, leftPaths = 0;
                int diagScore = 0, diagPaths = 0;
                char ch = board[i][j];

                if (isValid(i - 1, j, board)) {              // move up
                    auto [score, paths] = t[i - 1][j];       //solve(i-1, j)
                    upScore = score;
                    upPaths = paths;
                    if (upPaths > 0)
                        upScore += getIntFromChar(ch);
                }
                if (isValid(i, j - 1, board)) {              // move left
                    auto [score, paths] = t[i][j - 1];       //solve(i, j-1)
                    leftScore = score;
                    leftPaths = paths;
                    if (leftPaths > 0)
                        leftScore += getIntFromChar(ch);
                }
                if (isValid(i - 1, j - 1, board)) {          // move up-left
                    auto [score, paths] = t[i - 1][j - 1];   //solve(i-1, j-1)
                    diagScore = score;
                    diagPaths = paths;
                    if (diagPaths > 0)
                        diagScore += getIntFromChar(ch);
                }

                int bestScore, bestPaths;
                if (upScore == leftScore && leftScore == diagScore) {
                    bestScore = upScore;
                    bestPaths = upPaths + leftPaths + diagPaths;
                } else if (upScore == leftScore) {
                    bestScore = upScore;
                    bestPaths = upPaths + leftPaths;
                    if (diagScore > bestScore || (diagScore == bestScore && diagPaths > bestPaths)) {
                        bestScore = diagScore; bestPaths = diagPaths;
                    }
                } else if (leftScore == diagScore) {
                    bestScore = leftScore;
                    bestPaths = leftPaths + diagPaths;
                    if (upScore > bestScore || (upScore == bestScore && upPaths > bestPaths)) {
                        bestScore = upScore; bestPaths = upPaths;
                    }
                } else {
                    bestScore = upScore; bestPaths = upPaths;
                    if (leftScore > bestScore || (leftScore == bestScore && leftPaths > bestPaths)) {
                        bestScore = leftScore; bestPaths = leftPaths;
                    }
                    if (diagScore > bestScore || (diagScore == bestScore && diagPaths > bestPaths)) {
                        bestScore = diagScore; bestPaths = diagPaths;
                    }
                }

                t[i][j] = {bestScore, bestPaths % MOD};
            }
        }

        auto result = t[n - 1][n - 1]; //solve(n-1, n-1)
        return {result.first, result.second};
    }
};
