class Solution {
  public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        // code here
        int n = arr.size();
        deque<int> maxDeque, minDeque;  
        int start = 0, maxLen = 0, bestStart = 0;

        for (int end = 0; end < n; end++) { 
            // Maintain maxDeque (Monotonic Decreasing)
            while (!maxDeque.empty() && arr[maxDeque.back()] <= arr[end]) 
                maxDeque.pop_back();
            maxDeque.push_back(end);

            // Maintain minDeque (Monotonic Increasing)
            while (!minDeque.empty() && arr[minDeque.back()] >= arr[end]) 
                minDeque.pop_back();
            minDeque.push_back(end);

            // Shrink window if max - min > x
            while (arr[maxDeque.front()] - arr[minDeque.front()] > x) {
                start++;
                if (maxDeque.front() < start) maxDeque.pop_front();
                if (minDeque.front() < start) minDeque.pop_front();
            }

            // Update max length and best start index
            if (end - start + 1 > maxLen) {
                maxLen = end - start + 1;
                bestStart = start;
            }
        }

        return vector<int>(arr.begin() + bestStart, arr.begin() + bestStart + maxLen);
    }
};
