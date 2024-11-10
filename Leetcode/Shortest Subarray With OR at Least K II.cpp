//Leetcode Link : https://leetcode.com/problems/shortest-subarray-with-or-at-least-k-ii

//Approach - Simple using OR property and sliding window
//T.C : O(n)
//S.C : O(1)
class Solution {
public:

    void update(int number, vector<int>& vec, int val) {
        for(int i = 0; i < 32; i++) { //O(32)
            if((number >> i) & 1) {
                vec[i] += val;
            }
        }
    }

    int getDecimalFromBinary(vector<int>& vec) {
        int num = 0;

        for(int i = 0; i < 32; i++) { //O(32)
            if(vec[i] > 0) { //ith position me 1 hai
                num |= (1 << i);
            }
        }

        return num;
    }

    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();

        int result = INT_MAX;

        int i = 0;
        int j = 0;

        vector<int> vec(32, 0);
        //vec[i] = total number of set bits in ith position

        //T.C : O(2*n)
        while(j < n) { //O(n)
            update(nums[j], vec, 1); //adding in the current window

            while(i <= j && getDecimalFromBinary(vec) >= k) {
                result = min(result, j-i+1);
                update(nums[i], vec, -1); //remove the nums[i] from the window
                i++;
            }

            j++;
        }

        return result == INT_MAX ? -1 : result;
    }
};
