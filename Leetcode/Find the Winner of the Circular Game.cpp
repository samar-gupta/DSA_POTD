//Company Tags  : Goldman Sachs, Amazon
//Leetcode Link : https://leetcode.com/problems/find-the-winner-of-the-circular-game

//Approach-1 (Brute Force - Simple Simulation)
//T.C : O(n^2)
//S.C : O(n)
class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> arr;
        for(int i = 1; i <= n; i++) {
            arr.push_back(i);
        }

        int i = 0; //Game starts from 1st player which is sitting at index 0 in arr

        while(arr.size() > 1) {
            int idx = (i + k - 1) % arr.size();

            arr.erase(arr.begin() + idx);

            i = idx;
        }

        return arr[0];
    }
};


//Approach-1 (Using Queue for Simulation)
//T.C : O(n*k)
//S.C : O(n)
class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> que;
        for(int i = 1; i <= n; i++) {
            que.push(i);
        }

        while(que.size() > 1) {

            for(int count = 1; count <= k-1; count++) {
                que.push(que.front());
                que.pop();
            }

            que.pop();

        }

        return que.front();
    }
};


//Approach-3 (Using Recursion)
//T.C : O(n)
//S.C : O(1), but note that it will take o(n) system stack space
class Solution {
public:

    int findWinnerIdx(int n, int k) {
        if(n == 1) {
            return 0; //index
        }

        int idx = findWinnerIdx(n-1, k);
        idx = (idx + k) % n; //to find the original index in the original array

        return idx;
    }

    int findTheWinner(int n, int k) {
        
        int result_idx = findWinnerIdx(n, k);


        return result_idx + 1;

    }
};
