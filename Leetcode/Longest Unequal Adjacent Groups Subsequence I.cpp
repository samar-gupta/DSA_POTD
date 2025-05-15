//Leetcode Link : https://leetcode.com/problems/longest-unequal-adjacent-groups-subsequence-i

//Approach (Counting groups)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();

        vector<string> result;
        for(int i = 0; i < n; i++) {
            if(i == 0 || groups[i] != groups[i-1]) { //new group started, so pick the first element
                result.push_back(words[i]);
            }
        }

        return result;
    }
};
