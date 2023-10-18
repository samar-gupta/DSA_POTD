/*
    Company Tags                : Uber
    Leetcode Link               : https://leetcode.com/problems/parallel-courses-iii/
*/

/****************************************************** C++ ******************************************************/
//Company Tags : Uber
//Approach-1 (Using Simple Topological sorting)
//T.C : O(V+E),  S.C : O(V+E)
class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(n, 0);

        for(int i = 0; i<relations.size(); i++) {
            int u = relations[i][0] - 1;
            int v = relations[i][1] - 1;

            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> que;
        vector<int> maxTime(n, 0);      //maxTime[i] = maximum time taken by ith course to complete

        for(int i=0; i<n; i++) {
            if(indegree[i] == 0) {
                que.push(i);
                maxTime[i] = time[i];
            }
        }

        while(!que.empty()) {
          
            int u = que.front();
            que.pop();

            for(auto &v : adj[u]) {
              
                maxTime[v] = max(maxTime[v], maxTime[u] + time[v]);         //Finishing time of v will depend on the maximum time of its pre-requisites

                indegree[v]--;
                if(indegree[v] == 0) {
                    que.push(v);
                }

            }

        }

        return *max_element(begin(maxTime), end(maxTime));
    }
}
