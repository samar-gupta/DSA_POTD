//Leetcode Link : https://leetcode.com/problems/maximum-matching-of-players-with-trainers

//Approach (Using sorting + greedily selecting)
//T.C : O(nlogn + mlogm + min(m, n)), where m = size of players and n = size of trainers
//S.C : O(1)
class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int m = players.size();
        int n = trainers.size();
        sort(begin(players), end(players));
        sort(begin(trainers), end(trainers));

        int count = 0;
        int i = 0;
        int j = 0;

        while(i < m && j < n) {
            if(players[i] <= trainers[j]) {
                count++;
                i++;
            }
            j++;
        }

        return count;
    }
};
