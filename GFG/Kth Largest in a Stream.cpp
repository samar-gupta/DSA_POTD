class Solution {
  public:
    vector<int> kthLargest(vector<int>& arr, int k) {
        // code here
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        vector<int> result;
        
        for (int num : arr) {
            minHeap.push(num);
            
            if (minHeap.size() > k) {
                minHeap.pop();
            }
            
            if (minHeap.size() < k) {
                result.push_back(-1);
            } else {
                result.push_back(minHeap.top());
            }
        }
        
        return result;
    }
};
