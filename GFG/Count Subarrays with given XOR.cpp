//Approach : (Using Prefix XOR)
//T.C : O(n) , where n is the size of the input array. We traverse the array once and perform O(1) operations for each element.
//S.C : O(n) , for storing the prefix XORs in the hash map.
class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        unordered_map<int, int> xorMap; // Map to store frequency of prefix XORs
        int count = 0; for storing the prefix XORs in the hash map.                // To count the number of subarrays
        int currentXor = 0;            // Initialize prefix XOR

        for (int num : arr) {
            currentXor ^= num; // Update the prefix XOR

            // Check if the prefix XOR equals k
            if (currentXor == k) {
                count++;
            }

            // Check if there exists a prefix XOR that gives the required XOR with k
            int requiredXor = currentXor ^ k;
            if (xorMap.find(requiredXor) != xorMap.end()) {
                count += xorMap[requiredXor];
            }

            // Update the frequency of the current prefix XOR in the map
            xorMap[currentXor]++;
        }

        return count;
    }
};
