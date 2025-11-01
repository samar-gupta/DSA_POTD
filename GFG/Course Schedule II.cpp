//Approach-1 :
//T.C : O(n+m) 
//S.C : O(n+m) 
/* Algorithm:
    1. If course x is necessary for course y, then have a directed arrow from x to y.
    2. Course having 0 in-degree can be done without any prerequisites. Push to queue.
    3. For every element in queue ( these will have 0 in-degree ), add to answer and whichever course's prerequisite they belonged to, decrease their indegree by 1.
    4. If the new in degree is 0, that means now that particular course can be done and its pre-req courses are done. Push to Queue.
*/
class Solution {
  public:
    vector<int> findOrder(int n, vector<vector<int>> &prerequisites) {
        // code here
        vector<int> adj[n];
        vector<int> indegree(n, 0);
        for (auto &p : prerequisites) {
            adj[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }
        
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) q.push(i);
        }
        
        vector<int> ans;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            ans.push_back(curr);
            for (auto it : adj[curr]) {
                indegree[it]--;
                if (indegree[it] == 0) q.push(it);
            }
        }
        
        if (ans.size() == n) 
            return ans;
        return {};
    }
};
