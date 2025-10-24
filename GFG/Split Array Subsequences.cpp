//Approach-1 : 
class Solution {
  public:
    bool isPossible(vector<int>& arr, int k) {
        // code here
        unordered_map<int, int> count, end;

        // Step 1: Count occurrences
        for (int num : arr) 
            count[num]++;

        // Step 2: Try to form subsequences
        for (int num : arr) {
            if (count[num] == 0) continue;

            // If we can extend a previous subsequence
            if (end[num - 1] > 0) {
                end[num - 1]--;
                end[num]++;
                count[num]--;
            } 
            // Try to create a new subsequence
            else {
                int possible = true;
                for (int i = 0; i < k; i++) {
                    if (count[num + i] <= 0) {
                        possible = false;
                        break;
                    }
                }

                if (!possible) return false;

                // Decrement counts for new subsequence
                for (int i = 0; i < k; i++) 
                    count[num + i]--;
            
                end[num + k - 1]++;
            }
        }
        return true;
    }
};
