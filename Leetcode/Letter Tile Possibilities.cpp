//Leetcode Link : https://leetcode.com/problems/letter-tile-possibilities

//Approach-1 (Using simple backtracking Khandani Template)
//T.C : O(n!)
//S.C : O(n * n!), total possible sequences = n! and each having n length
class Solution {
public:
    int n;

    void solve(string& tiles, vector<bool>& used, unordered_set<string>& result, string &curr) {
        result.insert(curr);

        for(int i = 0; i < n; i++) {
            if(used[i])
                continue;

            curr.push_back(tiles[i]);
            used[i] = true;

            solve(tiles, used, result, curr);

            used[i] = false;
            curr.pop_back();
        }
    }

    int numTilePossibilities(string tiles) {
        n = tiles.length();
        vector<bool> used(n, false);
        unordered_set<string> result;
        string curr = "";

        solve(tiles, used, result, curr);

        return result.size()-1;
    }
};


//Approach-2 (Using count of characters + backtracking)
//T.C : O(n!)
//S.C : O(n), total possible sequences = n! and each having n length
class Solution {
public:
    int total;
    void findSequences(vector<int>& count) {
        total++;

        for (int pos = 0; pos < 26; pos++) {
            if (count[pos] == 0) {
                continue;
            }

            count[pos]--;
            findSequences(count);
            count[pos]++;
        }
    }

    int numTilePossibilities(std::string tiles) {
        total = 0;

        vector<int> count(26, 0);
        for (char c : tiles) {
            count[c - 'A']++;
        }

        findSequences(count);
        return total-1;
    }
};
