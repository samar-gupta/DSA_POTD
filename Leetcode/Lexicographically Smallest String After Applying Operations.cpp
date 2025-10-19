//Leetcode Link : https://leetcode.com/problems/lexicographically-smallest-string-after-applying-operations

//Approach-1 (Using BFS)
//T.C : O(n^2)
//S.C : O(n^2)
class Solution {
public:
    void rotate(string &s, int b) {
        reverse(begin(s), end(s));
        reverse(begin(s), begin(s) + b);
        reverse(begin(s) + b, end(s));
    }

    string findLexSmallestString(string s, int a, int b) {
        string smallestString = s;

        unordered_set<string> visited;
        queue<string> que;
        que.push(s);
        visited.insert(s);

        while(!que.empty()) {
            string curr = que.front();
            que.pop();

            if(curr < smallestString) {
                smallestString = curr;
            }

            //Add a to the digits
            string temp = curr;
            for(int i = 1; i < temp.length(); i+=2) {
                temp[i] = ((temp[i] - '0' + a) % 10) + '0';
            }

            if(!visited.count(temp)) {
                visited.insert(temp);
                que.push(temp);
            }

            //Rotate right by b
            rotate(curr, b);
            if(!visited.count(curr)) {
                visited.insert(curr);
                que.push(curr);
            }
        }

        return smallestString;

    }
};


//Approach-2 (Using DFS)
//T.C : O(n^2)
//S.C : O(n^2)
class Solution {
public:
    void rotate(string &s, int b) {
        reverse(begin(s), end(s));
        reverse(begin(s), begin(s) + b);
        reverse(begin(s) + b, end(s));
    }

    void dfs(string curr, int a, int b, unordered_set<string> &visited, string &smallestString) {
        if (visited.count(curr)) return;
        visited.insert(curr);
        if (curr < smallestString) smallestString = curr;

        string added = curr;
        for (int i = 1; i < added.size(); i += 2)
            added[i] = ((added[i] - '0' + a) % 10) + '0';
        dfs(added, a, b, visited, smallestString);

        rotate(curr, b);
        dfs(curr, a, b, visited, smallestString);
    }

    string findLexSmallestString(string s, int a, int b) {
        unordered_set<string> visited;
        string smallestString = s;
        dfs(s, a, b, visited, smallestString);
        return smallestString;
    }
};
