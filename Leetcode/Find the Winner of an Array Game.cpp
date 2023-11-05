/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=0pnrbej1_xM
    Company Tag                 : Will update soon
    Leetcode Link               : https://leetcode.com/problems/find-the-winner-of-an-array-game/
*/

/******************************************************** C++ ********************************************************/
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();

        int maxEl = *max_element(arr.begin(), arr.end());

        if(k >= n) {                //rotate - > maxEle will come at index 0 atleast once
            return maxEl;
        }

        int winner = arr[0];
        int wins = 0;              //streak

        for(int i = 1; i < n; i++) {

            if(winner > arr[i]) {
                wins++;
            } else {
                winner = arr[i];
                wins = 1;
            }

            if(wins == k || winner == maxEl) {
                return winner;
            }
        }

        return winner;
    }
};
