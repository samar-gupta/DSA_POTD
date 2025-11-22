//Leetcode Link : https://leetcode.com/problems/find-minimum-operations-to-make-all-elements-divisible-by-three/description/

//Approach-1: Simple Loop
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int operations = 0;
        
        for (int &num: nums) {
            // Goal: Make every number divisible by 3.
            // num % 3 gives the remainder:
            //
            // 0 → already divisible (O operations)
            // 1 → subtract 1 (1 operation)
            // 2 → add 1 (1 operation)
            //
            // So any number with remainder != 0 needs exactly 1 operation.
            if (num % 3 != 0) {
                operations++;            
            }
        }
        
        return operations;
    }
};


//Approach-2: Using C++ STL (Cleaner & Shorter)
class Solution {
public:
    int minimumOperations (vector<int>& nums) {
      // Count elements that are NOT divisible by 3.
      return count_if(nums.begin(), nums.end(), 
        [](int num) { return num % 3 != 0; }); 
    }
};
