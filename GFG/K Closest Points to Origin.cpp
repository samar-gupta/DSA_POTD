class Solution {
  public:
  
    static int distance(vector<int>& point) {
        return point[0] * point[0] + point[1] * point[1]; // Squared Euclidean distance
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Your code here
        auto compare = [](vector<int>& a, vector<int>& b) {
            return distance(a) < distance(b); // Max heap based on distance
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(compare)> pq(compare);
  
        for (auto& pt : points) {
            pq.push(pt);
            if (pq.size() > k) {
                pq.pop(); // Remove the farthest point
            }
        }
  
        // Store the k closest points in a vector
        vector<vector<int>> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top());
            pq.pop();
        }
        
        return ans;
    }
};
