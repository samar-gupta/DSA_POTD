//Leetcode Link : https://leetcode.com/problems/maximum-candies-you-can-get-from-boxes

//Approach-1 (Using DFS)
//T.C : O(n), where n =  number of boxes, we don't visit any box more than once
//S.C : O(n)
class Solution {
public:

    int dfs(int box, vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, unordered_set<int>& visited, unordered_set<int>& foundBoxes) {
        
        if(visited.count(box)) {
            return 0;
        }

        if(status[box] == 0) {
            foundBoxes.insert(box);
            return 0;
        }

        visited.insert(box);
        int candiesCollected = candies[box];


        for(int &insideBox : containedBoxes[box]) {
            candiesCollected += dfs(insideBox, status, candies, keys, containedBoxes, visited, foundBoxes);
        }

        for(int &boxKey : keys[box]) {
            status[boxKey] = 1; //can be opened
            if(foundBoxes.count(boxKey)) {
                candiesCollected += dfs(boxKey, status, candies, keys, containedBoxes, visited, foundBoxes);
            }
        }

        return candiesCollected;

    }

    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        
        int candiesCollected = 0;
        unordered_set<int> visited;
        unordered_set<int> foundBoxes;
        //T.C : O(n) visiting all box only once , n = number of boxes
        //S.C : O(n)
        for(int &box : initialBoxes) {
            candiesCollected += dfs(box, status, candies, keys, containedBoxes, visited, foundBoxes);
        }

        return candiesCollected;
    }
};


//Approach-2 (Using BFS)
//T.C : O(n), where n =  number of boxes, we don't visit any box more than once
//S.C : O(n)
class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        
        int candiesCollected = 0;
        unordered_set<int> visited;
        unordered_set<int> foundBoxes;
        //T.C : O(n) visiting all box only once , n = number of boxes
        //S.C : O(n)

        queue<int> que; //insert those which you have now and you can open it
        for(int &box : initialBoxes) {
            foundBoxes.insert(box);
            if(status[box] == 1) {
                que.push(box);
                visited.insert(box);
                candiesCollected += candies[box];
            }
        }

        while(!que.empty()) {
            int box = que.front();
            que.pop();

            for(int &insideBox : containedBoxes[box]) {
                foundBoxes.insert(insideBox);
                if(status[insideBox] == 1 && !visited.count(insideBox)) {
                    que.push(insideBox);
                    visited.insert(insideBox);
                    candiesCollected += candies[insideBox];
                }
            }

            for(int &boxKey : keys[box]) {
                status[boxKey] = 1; //can be opened in future if we reach this box
                if(foundBoxes.count(boxKey) && !visited.count(boxKey)) {
                    que.push(boxKey);
                    visited.insert(boxKey);
                    candiesCollected += candies[boxKey];
                }
            }
        }

        return candiesCollected;
    }
};
