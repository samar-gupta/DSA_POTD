//Leetcode Link : https://leetcode.com/problems/score-of-a-string/

//Approach : (Using Simple Iteration)
class Solution {
public:
    int scoreOfString(string s) {
        int score = 0;
        
        for(int i = 0; i < s.length()-1; i++) {
            score += abs(s[i] - s[i+1]);
        }
        
        return score;
    }
};



//Approach : (Using C++ STL)
class Solution {
public:
    int scoreOfString(string s) {
        return inner_product(s.begin(), s.end() - 1, s.begin() + 1, 0, plus<>(), [](char a, char b) {
            return abs(a - b);
        });
    }
};
