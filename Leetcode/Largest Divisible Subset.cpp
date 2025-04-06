//Company Tags    : GOOGLE
//Leetcode Link   : https://leetcode.com/problems/largest-divisible-subset/

//Approach-1 (Using Brute Force same as LIS) (TLE)
//T.C : O(2^n) (Recursion) without memoization
//S.C : O(n)
class Solution {
public:

    void solve(int idx, vector<int>& nums, vector<int>& result, vector<int> &temp, int prev) {
        if(idx >= nums.size()) {
            if(temp.size() > result.size()) {
                result = temp;
            }

            return;
        }

        if(prev == -1 || nums[idx] % prev == 0) {                //Take option
            temp.push_back(nums[idx]);                          //take
            solve(idx+1, nums, result, temp, nums[idx]);
            temp.pop_back();                                  //for not_take (as reference '&' is passed)
        }

        solve(idx+1, nums, result, temp, prev);
    }

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(begin(nums), end(nums));

        vector<int> result;
        vector<int> temp;
        int prev = -1;

        solve(0, nums, result, temp, prev);

        return result;
    }
};


//Approach-2 (Using Bottom Up same as LIS) - Just need to keep track of how to print LIS
//T.C : O(n^2)
//S.C : O(n)
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(begin(nums), end(nums));

        int n = nums.size();

        vector<int> t(n, 1);
        vector<int> prev_idx(n, -1);

        int last_chosen_index = 0;
        int maxL = 1;

        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {

                if(nums[i] % nums[j] == 0) {
                    if(t[i] < t[j]+1) {
                        t[i] = t[j] + 1;
                        prev_idx[i] = j;
                    }

                    if(t[i] > maxL) {
                        maxL = t[i];
                        last_chosen_index = i;
                    }
                }

            }
        }

        vector<int> result;
        while(last_chosen_index != -1) {                    
            result.push_back(nums[last_chosen_index]);
            last_chosen_index = prev_idx[last_chosen_index];
        }
        
        return result;          //[2,1]  (as we can return in any order)   //sort(begin(result), end(result));   //[1,2]
    }
};
