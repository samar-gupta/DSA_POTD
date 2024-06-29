//


class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        // Create adjacency list
        vector<vector<int>> adjacencyList(n);

        // Fill the adjacency list and indegree array based on the edges
        vector<int> indegree(n, 0);
        for (auto& edge : edges) {
            int from = edge[0];
            int to = edge[1];
            adjacencyList[from].push_back(to);
            indegree[to]++;
        }

        queue<int> nodesWithZeroIndegree;
        for (int i = 0; i < indegree.size(); i++) {
            if (indegree[i] == 0) {
                nodesWithZeroIndegree.push(i);
            }
        }

        // List to store the topological order of nodes
        vector<int> topologicalOrder;
        while (!nodesWithZeroIndegree.empty()) {
            int currentNode = nodesWithZeroIndegree.front();
            nodesWithZeroIndegree.pop();
            topologicalOrder.push_back(currentNode);

            // Reduce indegree of neighboring nodes and add them to the queue
            // if they have no more incoming edges
            for (int neighbor : adjacencyList[currentNode]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    nodesWithZeroIndegree.push(neighbor);
                }
            }
        }

        // Initialize the result list and set list for storing ancestors
        vector<vector<int>> ancestorsList(n);
        vector<unordered_set<int>> ancestorsSetList(n);

        // Fill the set list with ancestors using the topological order
        for (int node : topologicalOrder) {
            for (int neighbor : adjacencyList[node]) {
                // Add immediate parent, and other ancestors
                ancestorsSetList[neighbor].insert(node);
                ancestorsSetList[neighbor].insert(
                    ancestorsSetList[node].begin(),
                    ancestorsSetList[node].end());
            }
        }

        // Convert sets to lists and sort them
        for (int i = 0; i < ancestorsList.size(); i++) {
            ancestorsList[i].assign(ancestorsSetList[i].begin(),
                                    ancestorsSetList[i].end());
            sort(ancestorsList[i].begin(), ancestorsList[i].end());
        }

        return ancestorsList;
    }
};

