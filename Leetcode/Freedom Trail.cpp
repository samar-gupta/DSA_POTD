//Company Tags  : Google
//Leetcode Link : https://leetcode.com/problems/freedom-trail

//Approach-1 (Recursion  + Memoization)
//T.C : Without Memoization : O(n^m), where n is the length of the ring string and m is the length of the key string. This is because for each character in the key, 
                             //the algorithm will explore all possible positions in the ring string recursively, without reusing any previous results.
        //With Memoization  : O(n^2 * m)
//S.C : O(101*101) ~ O(1)
class Solution {
public:
    int t[101][101];
    
    int countSteps(int ringIndex, int i, int n) {
        int dist       = abs(i - ringIndex);
        int wrapAround =  n - dist;
        
        return min(dist, wrapAround);
    }
    
    int solve(int ringIndex, int keyIndex, string& ring, string& key) {
        
        if (keyIndex == key.length()) {
            return 0;
        }
        
        if(t[ringIndex][keyIndex] != -1) {
            return t[ringIndex][keyIndex];
        }
        
        int result = INT_MAX;
        for (int i = 0; i < ring.length(); i++) {
            if (ring[i] == key[keyIndex]) {
                int totalSteps = countSteps(ringIndex, i, ring.length()) + 1 +
                                            solve(i, keyIndex + 1, ring, key);
                result = min(result, totalSteps);
            }
        }
        
        return t[ringIndex][keyIndex] = result;
    }
    
    int findRotateSteps(string ring, string key) {
        memset(t, -1, sizeof(t));
        return solve(0, 0, ring, key);
    }
};



//Approach-2 (Bottom Up)
//T.C : O(n^2 * m)
//S.C : O(n*m)
//State Def - t[ringIndex][keyIndex] = minimum number of steps to get key[keyIndex] when the ring[ringIndex] is aligned with the "12:00" position.
class Solution {
public:
    int countSteps(int ringIndex, int i, int n) {
        int dist       = abs(i - ringIndex);
        int wrapAround =  n - dist;
        
        return min(dist, wrapAround);
    }
    
    int findRotateSteps(string ring, string key) {
        int n = ring.length();
        int m = key.length(); 
        
        vector<vector<int>> t(n+1, vector<int>(m+1, INT_MAX));
        //t[ringIndex][keyIndex] = minimum number of steps to get key[keyIndex] when the ring[ringIndex] is aligned with the "12:00" position.
        
        //If 
        for(int ringIndex = 0; ringIndex < n; ringIndex++) {
            t[ringIndex][m] = 0; //base case when all key chars are done (we reached index n)
        }
    
        for(int keyIndex = m-1; keyIndex >= 0; keyIndex--) {
            for(int ringIndex = 0; ringIndex < n; ringIndex++) {
                
                 int result = INT_MAX;
                 for (int i = 0; i < ring.length(); i++) {
                    if (ring[i] == key[keyIndex]) {
                        int totalSteps = countSteps(ringIndex, i, ring.length()) + 1 +
                                                    t[i][keyIndex + 1];
                        result = min(result, totalSteps);
                    }
                }
                t[ringIndex][keyIndex] = result;
            }
        }
        return t[0][0];
    }
};
