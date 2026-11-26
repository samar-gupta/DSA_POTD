//Leetcode Link : https://leetcode.com/problems/stone-removal-game/

//Approach-1 Simulation
//T.C : O(1) 
//S.C : O(1)
class Solution {
public:
    bool canAliceWin(int n) {
        int take = 10;
        int steps = 0;

        while (n >= take) {
            n -= take;
            take--;
            steps++;
        }

        return steps % 2 == 1;
    }
};



//Approach-2 Maths
//T.C : O(1) 
//S.C : O(1)
class Solution {
public:
    bool canAliceWin(int n) {
        int k = (21 - sqrt(441 - 8*n)) / 2;

        return k%2 == 1; //odd : ALice wins
    }
};
