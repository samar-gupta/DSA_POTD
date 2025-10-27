//Approach-1 : (using a min-heap (priority queue) and a set to avoid duplicates. This approach is suitable for two sorted arrays)
//This code finds the k pairs with the smallest sums by always choosing the next minimum possible sum, and avoids repeating the same index combination using a set
/*
T.C : O(klogk)
   Each insertion and removal operation in the min-heap (priority queue) takes [O(\log k)] time.
   At most [k] pairs are processed, as the loop runs up to [k] times.
   Therefore, the total time complexity is [O(k \log k)].
S.C : O(k)
   The priority queue (min-heap) may store up to [k] pairs simultaneously, leading to [O(k)] space usage.
   The visited set also holds up to [k] pairs for duplicate tracking, giving another [O(k)] space.
   The final result vector stores [k] pairs, which is [O(k)] as well
*/
class Solution {
  public:
    vector<vector<int>> kSmallestPair(vector<int> &arr1, vector<int> &arr2, int k) {
        // code here
        vector<vector<int>> result;
        int n1 = arr1.size(), n2 = arr2.size();
        if (n1 == 0 || n2 == 0 || k == 0) return result;
        
        // Min-heap to store sum and the pair indices
        typedef tuple<int, int, int> t3; // {sum, i, j}
        priority_queue<t3, vector<t3>, greater<t3>> pq;
        set<pair<int, int>> visited;

        // Initial pair (0, 0)
        pq.push({arr1[0] + arr2[0], 0, 0});
        visited.insert({0, 0});
        
        while (k-- && !pq.empty()) {
            auto [sum, i, j] = pq.top();
            pq.pop();
            result.push_back({arr1[i], arr2[j]});

            // Move to next in arr1
            if (i + 1 < n1 && visited.find({i + 1, j}) == visited.end()) {
                pq.push({arr1[i + 1] + arr2[j], i + 1, j});
                visited.insert({i + 1, j});
            }
            // Move to next in arr2
            if (j + 1 < n2 && visited.find({i, j + 1}) == visited.end()) {
                pq.push({arr1[i] + arr2[j + 1], i, j + 1});
                visited.insert({i, j + 1});
            }
        }
        return result;
    }
};
