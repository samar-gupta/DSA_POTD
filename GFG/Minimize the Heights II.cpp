//Approach-1 : (Using Sorting)
class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        if (n == 1) return 0;  // If there's only one tower, difference is 0.
        
        // Sort the array to handle elements in order.
        sort(arr.begin(), arr.end());

        // Initialize the result as the difference between the max and min height in the sorted array.
        int result = arr[n - 1] - arr[0];

        // The smallest possible height and largest possible height after adjusting with k
        int smallest = arr[0] + k;
        int largest = arr[n - 1] - k;

        // Traverse through the array to explore the different possibilities
        for (int i = 0; i < n - 1; i++) {
            int minHeight = min(smallest, arr[i + 1] - k);
            int maxHeight = max(largest, arr[i] + k);
            
            // If the new height is negative, skip to avoid invalid cases
            if (minHeight < 0) continue;

            // Update the result with the minimum possible difference
            result = min(result, maxHeight - minHeight);
        }

        return result;
    }
};


//old
class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        sort(arr.begin(),arr.end());
        int mini = arr[0] + k;
        int maxi = arr[n-1] - k;
        int ans = arr[n-1] - arr[0];
        for(int i = 0;i<arr.size();i++){
            int low = min(mini,arr[i+1] - k);
            int high = max(maxi,arr[i] + k);
            if(low>=0){
                ans = min(ans,abs(high-low));
            }
        }
        
        return ans;
    }
};
