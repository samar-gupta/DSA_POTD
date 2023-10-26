/*
    Company Tags                : GOOGLE
    Leetcode Link               : https://leetcode.com/problems/binary-trees-with-factors/
*/

/************************************************ C++ ************************************************/
//T.C : O(n^2)   , O(n^2) for 2 loops and O(nlogn) for sorting but since O(n^2) is larger. Hence T.C : O(n^2)
//S.C : O(n)
class Solution {
public:

    int MOD = 1e9+7;

    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size();

        sort(begin(arr), end(arr));

        unordered_map<int, long long> mp;
        mp[arr[0]] = 1;

        for(int i = 1; i<n; i++) {
            int root = arr[i];
            mp[root] = 1;

            for(int j = 0; j<i; j++) {

                int LC = arr[j];

                if(root%LC == 0 && mp.find(arr[i]/LC) != mp.end()) {           //RC = arr[i]/LC , (rightChild)
                    mp[root] += mp[LC] * mp[arr[i]/LC];
                }

            }

        }

        long result = 0;                                        //value -> number of ways of binary trees
        for(auto &it : mp) {                                   //it.first = value
            result = (result + it.second) % MOD;              //it.second = ways
        }

        return result;
    }
};
