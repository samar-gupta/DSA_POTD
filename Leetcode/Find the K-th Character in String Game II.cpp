//Leetcode Link : https://leetcode.com/problems/find-the-k-th-character-in-string-game-ii/description/

//Approach - Recursion
//T.C : O(log(k))
//S.C : O(log(k))) of system stack
class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        // Base case: If k is 1, the result is the initial character 'a'
        if (k == 1) {
            return 'a';
        }

        int n = operations.size();  // Size of the operations array
        int opType;                 // Store the operation type (0 or 1)
        long long len = 1;          // Start with length 1 (initial 'a')
        long long newK;             // To store the adjusted k value

        // Traverse through the operations array to determine the operation type
        for (int i = 0; i < n; i++) {
            len *= 2;               // Double the length at each step
            if (len >= k) {         // If the current length surpasses or equals k
                opType = operations[i];  // Get the current operation type
                newK = k - len / 2;      // Adjust k for the next recursive call
                break;                   // Break as we have found the required operation
            }
        }

        // Recursively find the character before the operation is applied
        char res = kthCharacter(newK, operations);
        
        // If operation type is 0, return the character as is
        if (opType == 0) 
            return res;

        // If operation type is 1, transform the character ('a' becomes 'b', etc.)
        if (res == 'z') 
            return 'a';  // Handle wrap-around from 'z' to 'a'
        
        return res + 1;   // Increment character by 1
    }
};
