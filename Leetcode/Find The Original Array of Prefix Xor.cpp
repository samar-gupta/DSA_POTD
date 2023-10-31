/*
      Company Tags                : Microsoft
      Leetcode Link               : https://leetcode.com/problems/find-the-original-array-of-prefix-xor
*/

/*************************************************** C++ ***************************************************/
//Approach-1 (Using extra array)
//T.C : O(n)
class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();

        vector<int> arr;
        arr.push_back(pref[0]);

        for(int i = 1; i<n; i++) {
            arr.push_back(pref[i] ^ pref[i-1]);
        }

        return arr;
    }
};




//Approach-2 (Without Using extra array)
//T.C : O(n)
class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();

        for(int i = n-1; i > 0; i--) {
            pref[i] = pref[i] ^ pref[i-1];
        }

        return pref;
    }
};
