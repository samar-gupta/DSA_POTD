//Leetcode Link : https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings

//Approach (Using simple backtracking)
//T.C : O(n*2^n)
//S.C : O(n)
class Solution {
public:

    void solve(string& s, int idx, unordered_set<string>& st, int currCount, int& maxCount) {
        if(currCount + (s.length() - idx) <= maxCount) { //Pruning for slight improvement
            return;
        }

        if(idx == s.length()) {
            maxCount = max(maxCount, currCount);
        }

        for(int j = idx; j < s.length(); j++) {
            string sub = s.substr(idx, j-idx+1);
            if(st.find(sub) == st.end()) {
                st.insert(sub);
                solve(s, j+1, st, currCount+1, maxCount);
                st.erase(sub);
            }
        }
    }

    int maxUniqueSplit(string s) {
        unordered_set<string> st;
        int maxCount  = 0;
        int currCount = 0;
        solve(s, 0, st, currCount, maxCount);

        return maxCount;
    }
};
