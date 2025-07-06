// Approach 1: Brute-force all pair sums, sort descending, pick top k.
// Time Complexity: O((n^2) log(n^2)) — generate n^2 sums and sort them.
// Space Complexity: O(n^2) — storing all n^2 pair sums.
class Solution {
public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        int n = a.size();

        // collect all possible sums of one element from 'a' and one from 'b'
        vector<int> combinedSum;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                combinedSum.push_back(a[i] + b[j]);  // push sum a[i] + b[j]
            }
        }

        // sort descending to bring largest sums to front
        sort(combinedSum.rbegin(), combinedSum.rend());

        // extract the top k sums
        vector<int> result;
        for (int idx = 0; idx < k; ++idx) {
            result.push_back(combinedSum[idx]);  // append the idx-th largest sum
        }

        return result;  // return top k sums
    }
};


// Approach 2: Max‑heap + visited set to merge two descending arrays and extract top k sums without generating all n^2 pairs.
// Time Complexity: O(n log n + k log k) — sorting two arrays in O(n log n) and performing k heap pops/pushes in O(k log k).
// Space Complexity: O(k) — heap and visited set hold up to O(k) entries.
class Solution {
public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        int n = a.size();

        // sort both arrays in descending order
        sort(a.rbegin(), a.rend());                     // O(n log n)
        sort(b.rbegin(), b.rend());                     // O(n log n)

        // max-heap storing {sum, {i, j}}
        priority_queue<pair<int, pair<int, int>>> pq;
        set<pair<int, int>> st;                          // visited index‑pairs

        // seed with the largest pair (0,0)
        pq.push({ a[0] + b[0], { 0, 0 } });
        st.insert({ 0, 0 });

        vector<int> result;
        result.reserve(k);

        while (result.size() < k) {
            auto top = pq.top(); pq.pop();              // pop current max sum
            int  sum = top.first;
            int  i   = top.second.first;
            int  j   = top.second.second;

            result.push_back(sum);                      // record it

            // push neighbor (i, j+1) if within bounds and not seen
            if (j + 1 < n && st.emplace(i, j + 1).second) {
                pq.push({ a[i] + b[j + 1], { i, j + 1 } });
            }
            // push neighbor (i+1, j) if within bounds and not seen
            if (i + 1 < n && st.emplace(i + 1, j).second) {
                pq.push({ a[i + 1] + b[j], { i + 1, j } });
            }
        }
        return result;  // top k sums
    }
};
