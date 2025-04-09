//Leetcode Link : https://leetcode.com/problems/minimum-operations-to-make-array-values-equal-to-k

//Approach (Using observation - counting unique)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> st;

        for(int &x : nums) {
            if(x < k) {
                return -1;
            } else if(x > k) {
                st.insert(x);  
            }
        }
        return st.size();
    }
};
