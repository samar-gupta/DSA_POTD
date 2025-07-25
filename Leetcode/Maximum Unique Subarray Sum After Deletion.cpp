//Leetcode Link : https://leetcode.com/problems/maximum-unique-subarray-sum-after-deletion

//Approach-1 (Using set)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> st;

        int sum = 0;

        int maxNeg = INT_MIN;

        for(int &num : nums) {
            if(num <= 0) {
                maxNeg = max(maxNeg, num);
            } else if(!st.count(num)) {
                sum += num;
                st.insert(num);
            }
        }
        
        return sum == 0 ? maxNeg : sum;
    }
};


//Approach-2 (Using constant space)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int maxSum(vector<int>& nums) {
        //unordered_set<int> st;
        vector<int> st(101, -1);

        int sum = 0;

        int maxNeg = INT_MIN;

        for(int &num : nums) {
            if(num <= 0) {
                maxNeg = max(maxNeg, num);
            } else if(st[num] == -1) {
                sum += num;
                //st.insert(num);
                st[num] = 1;
            }
        }
        
        return sum == 0 ? maxNeg : sum;
    }
};
