//Approach-1 : (using sorting with comarative function)
class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // code here
        sort(points.begin(), points.end(), [&](vector<int>& A, vector<int>& B) {
            return (A[0] * A[0] + A[1] * A[1]) < (B[0] * B[0] + B[1] * B[1]);
        });
        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
};


//Approach-2 : (Using maxHeap)
class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // code here
        vector<vector<int>> ans;
        priority_queue<pair<int, int>> pq;
        int n = points.size();
        for(int i=0; i<n; i++){
            int x=points[i][0], y=points[i][1];
            int dist=x*x+y*y;
            pq.push({dist, i});
            if(pq.size()>k) 
                pq.pop();
        }
        
        while(!pq.empty()){
            ans.push_back(points[pq.top().second]);
            pq.pop();
        }
        
        return ans;
    }
};


//Approach-3 : (Using minHeap)
class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // code here
        vector<vector<int>> ans;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int n=points.size();
        for(int i=0; i<n; i++){
            int x=points[i][0], y=points[i][1];
            int dist=x*x+y*y;
            pq.push({dist, i});
        }
        while(k > 0 && !pq.empty()){
            ans.push_back(points[pq.top().second]);
            pq.pop();
            k--;
        }
        return ans;
    }
};



//old
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
