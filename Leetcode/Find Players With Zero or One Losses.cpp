//Company Tags      : Google, Indeed
//Leetcode Link     : https://leetcode.com/problems/find-players-with-zero-or-one-losses/

//T.C : O(n*logn)
//S.C : O(n)
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> lost;
        
        for(auto &it : matches) {
            int lose = it[1];
            lost[lose]++;
        }
        
        vector<int> notLost;
        vector<int> oneLos;
        
        for(auto &it : matches) {
            int lose = it[1];
            int win  = it[0];
            
            if(lost[lose] == 1) {
                oneLos.push_back(lose);
            }
            if(lost.find(win) == lost.end()) {
                notLost.push_back(win);
                lost[win] = 2;
            }
            
        }
        
        sort(begin(notLost), end(notLost));
        sort(begin(oneLos), end(oneLos));
        
        return {notLost, oneLos};
        
    }
};
