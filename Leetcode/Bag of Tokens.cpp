//Company Tags   : Google
//Leetcode Link  : https://leetcode.com/problems/bag-of-tokens/

//T.C : O(nlogn)
//S.C : O(1)
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        sort(tokens.begin(), tokens.end());
        
        int score = 0;
        int maxScore  = 0;
        int i = 0, j = n-1;

        //:GREEDY
        //While losing power, I will choose the smallest token
        //While gainin power, I will choose the largest token
        
        while(i <= j) {
            if(power >= tokens[i]) {
                score++;
                maxScore = max(maxScore, score); //keep updating it
                power -= tokens[i]; //choose smallest token
                i++;
                
            } else if(score >= 1) {
                score--;
                power += tokens[j]; //choose largest token
                j--;
                
            } else {
                //no way further to increase score
                return maxScore;
            }
        }
        
        return maxScore;
    }
};
