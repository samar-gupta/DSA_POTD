//Leetcode Link : https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk

//Approach-1 - Simulation (TLE)
//T.C : O(k/sum * n)
//S.C : O(1)
class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        while(true) {
            for(int i = 0; i < chalk.size(); i++) {
                if(k < chalk[i]) {
                    return i;
                }
                k -= chalk[i];
            }
        }

        return -1;
    }
};



//Approach-2 (Making use of remainder)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();

        long long totalChalkSum = 0; //Total chalks required in one iteration
        for(int &chalkReq : chalk) { //O(n)
            totalChalkSum += chalkReq;
        }

        //Number of full iteration possible = k/totalChalkSum

        int remainChalk = k%totalChalkSum;

        for(int i = 0; i < n; i++) { //O(n)
            if(remainChalk < chalk[i]) {
                return i;
            }

            remainChalk -= chalk[i];
        }

        return -1;
    }
};
