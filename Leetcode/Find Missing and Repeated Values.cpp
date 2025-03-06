//Leetcode Link : https://leetcode.com/problems/find-missing-and-repeated-values

//Approach-1 (Simple using map)
//T.C : O(n^2)
//S.C : O(n^2)
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int N = n*n; //total elements

        unordered_map<int, int> mp;

        int a = -1;
        int b = -1;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                mp[grid[i][j]]++;
            }
        }

        //[1...N]
        for(int num = 1; num <= N; num++) {
            if(!mp.count(num)) {
                b = num;
            } else if(mp[num] == 2) {
                a = num;
            }

            if(a != -1 && b != -1) {
                break;
            }
        }

        return {a, b};
    }
};


//Approach-2 (using maths)
//T.C : O(n^2)
//S.C : O(n^2)
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();

        long long N = n*n;

        long long gridSum   = 0;
        long long gridSqSum = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                gridSum += grid[i][j];
                gridSqSum += grid[i][j]*grid[i][j];
            }
        }

        long long sum   = (N * (N+1))/2; //Expected sum of N natural numbers
        long long sqSum = (N * (N+1) * (2*N+1))/6; //Expected sq sum of natural numbers

        int sqDiff  = gridSqSum - sqSum;
        int sumDiff = gridSum - sum;

        int a = (sqDiff/sumDiff + sumDiff)/2; 
        int b = (sqDiff/sumDiff - sumDiff)/2;

        return {a, b};
    }
};
