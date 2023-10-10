/*
      Company Tags                : GOOGLE
      Leetcode Link               : https://leetcode.com/problems/minimum-number-of-operations-to-make-array-continuous/
*/

/************************************************ C++ ************************************************/
//Approach-2 (Optimal)
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        set<int> st(begin(nums), end(nums));                   // sorted, unique element int set

        vector<int> temp(begin(st), end(st));

        int result = INT_MAX;

        for(int i = 0; i<temp.size(); i++) {

            int left_range = temp[i];
            int right_range = left_range + n - 1;

            int j = upper_bound(begin(temp), end(temp), right_range) - begin(temp);

            int within_range = j - i;
            int out_of_range = n - within_range;

            result = min(result, out_of_range);
        }

        return result;
    }
};




//Approach-1 (Brute Force) - TLE
//T.C : O(n^2)
//S.C : O(n)
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        
        int result = INT_MAX;
        
        for(int i = 0; i < n; i++) {
            
            int left_range  = nums[i]; //L
            int right_range = left_range + n - 1;
            
            int mehnat = 0;
            
            unordered_set<int> used;
            
            for(int j = 0; j < n; j++) {
                
                if(nums[j] >= left_range && nums[j] <= right_range && used.find(nums[j]) == used.end()) {
                    used.insert(nums[j]);
                    continue;
                } else {
                    mehnat++;
                }
                
            }
            
            result = min(result, mehnat);
            
        }
        
        return result;
    }
};
