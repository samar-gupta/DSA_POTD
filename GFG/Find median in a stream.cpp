class Solution {
  public:
    void addNum(int num, priority_queue<int>& maxHeap, priority_queue<int, vector<int>, greater<int>>& minHeap) {
        if (maxHeap.empty() || num <= maxHeap.top()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }

        // Balance the heaps
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian(priority_queue<int>& maxHeap, priority_queue<int, vector<int>, greater<int>>& minHeap) {
        if (maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        } else {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }
    }
    
    vector<double> getMedian(vector<int> &arr) {
        // code here
        vector<double> res;
        priority_queue<int> maxHeap; // Max heap for the smaller half
        priority_queue<int, vector<int>, greater<int>> minHeap; // Min heap for the larger half

        for (int num : arr) {
            addNum(num, maxHeap, minHeap);
            res.push_back(findMedian(maxHeap, minHeap));
        }
        return res;
    }
};
