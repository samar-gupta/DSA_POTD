//Leetcode Link : https://leetcode.com/problems/rabbits-in-forest/description

//Approach (Grouping using map)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> mp;
        for (int& x : answers) {
            mp[x]++;
        }

        int total = 0;

        for (auto& it : mp) {
            int x     = it.first;  // The answer given by rabbit
            int count = it.second; // How many rabbits gave that answer

            int groupSize = x + 1;
            int groups    = ceil((double)count / groupSize);

            total += groups * groupSize;
        }

        return total;
    }
};
