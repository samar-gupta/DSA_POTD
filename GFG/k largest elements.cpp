class Solution {
  public:
    vector<int> kLargest(vector<int>& arr, int k) {
        // Your code here
        priority_queue<int, vector<int>, greater<int>> pq; // Min-Heap
  
        for (int num : arr) {
            pq.push(num);
            if (pq.size() > k)
                pq.pop(); // Remove the smallest element
        }
  
        vector<int> ans;
        while (!pq.empty()) {
            ans.insert(ans.begin(), pq.top()); // Insert at index 0
            pq.pop();
        }
  
        return ans;
    }
};
