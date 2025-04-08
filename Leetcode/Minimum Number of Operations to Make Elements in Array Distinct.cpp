//Leetcode Link : https://leetcode.com/problems/minimum-number-of-operations-to-make-elements-in-array-distinct

//Approach-1 (Brute Force)
//T.C : O(n^2)
//S.C : O(n)
class Solution {
public:
    int n;
    bool check(vector<int>& nums, int start) {
        unordered_set<int> st;
        for (int j = start; j < n; j++) {
            if (st.count(nums[j])) {
                return false;
            }
            st.insert(nums[j]);
        }
        return true;
    }
    int minimumOperations(vector<int>& nums) {
        n = nums.size();
        int ops = 0;
        for (int i = 0; i < n; i += 3) {
            if (check(nums, i) == true) {
                return ops;
            }
            ops++;
        }
        return ops;
    }
};


//Approach-2 (Using reverse loop)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();

        unordered_set<int> st;

        for(int i = n-1; i >= 0; i--) {
            if(st.count(nums[i])) {
                return ceil((i+1)/3.0);
            }
            st.insert(nums[i]);
        }

        return 0;
    }
};
