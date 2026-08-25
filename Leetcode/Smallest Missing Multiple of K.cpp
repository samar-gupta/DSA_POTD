//Leetcode Link : https://leetcode.com/problems/smallest-missing-multiple-of-k/description/

//Approach :
class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st(begin(nums), end(nums));

        int result = k;
        while (st.count(result)) {
            result += k;
        }

        return result;
    }
};
