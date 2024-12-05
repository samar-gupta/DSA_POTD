//Leetcode Link : https://leetcode.com/problems/move-pieces-to-obtain-a-string

//Approach-1 (Brute Force to check all possibilities)
//T.C : Exponential in the worst case due to exploring all possible swaps, though memoization reduces redundant computations.
//S.C : Memoization map to store all possible states. ~ O(n^2) states possible
class Solution {
public:
    int n;
    bool solve(string &start, string &target, unordered_map<string, bool>& mp) {
        if(start == target) {
            return true;
        }

        //Memoization
        if(mp.count(start)) {
            return mp[start];
        }

        for(int i = 0; i < start.length(); i++) {
            if(start[i] == 'L' && i > 0 && start[i-1] == '_') {
                swap(start[i], start[i-1]);
                if(solve(start, target, mp) == true) {
                    return true;
                }
                swap(start[i], start[i-1]);
            } else if(start[i] == 'R' && i < n-1 && start[i+1] == '_') {
                swap(start[i], start[i+1]);
                if(solve(start, target, mp) == true) {
                    return true;
                }
                swap(start[i], start[i+1]);
            }
        }

        return mp[start] = false;
    }

    bool canChange(string start, string target) {
        n = start.length();
        unordered_map<string, bool> mp;
        return solve(start, target, mp);
    }
};

//Approach-2 (Optimal using 2 pointers)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.length();
        int i = 0;
        int j = 0;

        while(i < n || j < n) {
            while(i < n && start[i] == '_') {
                i++;
            }

            while(j < n && target[j] == '_') {
                j++;
            }

            if(i == n || j == n) {
                return i == n && j == n;
            }

            if(start[i] != target[j]) {
                return false;
            }

            if(start[i] == 'L' && i < j) {
                return false;
            }

            if(start[i] == 'R' && i > j) {
                return false;
            }

            i++;
            j++;
            
        }

        return true;
    }
};
