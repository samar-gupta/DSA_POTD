/*Approach : I solved this using a mathematical observation. Instead of generating all subarrays, I figured out how many times each element at position i appears in all possible subarrays.
              For an element at index i in an array of size n:
              It can be the start of subarrays ending at positions i, i+1, i+2, ..., n-1 (that's n-i subarrays)
              It can be part of subarrays starting at positions 0, 1, 2, ..., i (that's i+1 starting positions)
              So total appearances = (i+1) × (n-i)
              I multiply each element by its frequency and sum them all up.
*/
//Time Complexity: O(n) - where n is the size of the array. I iterate through the array only once.
//Space Complexity: O(1) - I only use a few variables for calculation, no extra data structures.
class Solution {
  public:
    int subarraySum(vector<int>& arr) {
        // code here
        int n = arr.size();
        int totalSum = 0;
        
        // For each element, calculate how many times it appears in all subarrays
        for(int i = 0; i < n; i++) {
            // Element at index i appears in:
            // - Subarrays starting from 0 to i (i+1 choices for start)
            // - Subarrays ending from i to n-1 (n-i choices for end)
            // Total appearances = (i+1) * (n-i)
            int frequency = (i + 1) * (n - i);
            
            // Add this element's contribution to total sum
            totalSum += arr[i] * frequency;
        }
        
        return totalSum;
    }
};
