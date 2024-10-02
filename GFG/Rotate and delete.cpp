class Solution {
  public:
    int rotateDelete(vector<int> &arr) {
        // Your code here
        int n = arr.size(); // Get the initial size of the array
        int k = 1; // Start the operation count from 1

        // Continue the process until there is only one element left in the array
        while (n > 1) {
            // Step 1: Rotate the array by moving the last element to the front
            arr.insert(arr.begin(), arr[n - 1]); // Insert last element at the beginning
            arr.pop_back(); // Remove the last element (which has been moved)

            // Step 2: Calculate the index of the element to delete
            // The index to delete is (n - k), adjusting for 0-based index.
            int deleteIndex = n - k;
            if (deleteIndex < 0) deleteIndex = 0; // Edge case to avoid negative index

            // Remove the element at the calculated index
            arr.erase(arr.begin() + deleteIndex);

            // Increment k (operation count) and reduce the size n of the array
            ++k;
            --n;
        }

        // Return the last remaining element in the array
        return arr[0];
    }
};
