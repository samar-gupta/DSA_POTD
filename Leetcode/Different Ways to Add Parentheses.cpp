//Leetcode Link : https://leetcode.com/problems/different-ways-to-add-parentheses

//Approach-(Simple and straight forward convert to minutes and sort)
//T.C : O(n*2^n)
//S.C : O(2^n) //The result vector stores all possible outcomes. The number of results is at most exponential in terms of the number of operators, so the space required to store the results is O(2^n).
class Solution {
public:

    vector<int> solve(string s) {
        vector<int> result;

        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '+' || s[i] == '-' || s[i] == '*') {
                vector<int> left_results  = solve(s.substr(0, i));
                vector<int> right_results = solve(s.substr(i+1));

                for(int &x : left_results) {
                    for(int &y : right_results) {
                        if(s[i] == '+') {
                            result.push_back(x+y);
                        } else if(s[i] == '-') {
                            result.push_back(x-y);
                        } else {
                            result.push_back(x*y);
                        }
                    }
                }
            }
        }

        if(result.empty()) {
            result.push_back(stoi(s));
        }

        return result;
    }

    vector<int> diffWaysToCompute(string s) {
        return solve(s);
    }
};
