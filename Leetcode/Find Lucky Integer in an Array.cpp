//Leetcode Link : https://leetcode.com/problems/find-lucky-integer-in-an-array

//Approach-1 (Using fixed size array to store frequency)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> mp;
        
        for(int &x : arr) {
            mp[x]++;
        }
        
        int ans = -1;
        for(auto &it : mp) {
            if(it.first == it.second)
                ans = max(ans, it.first);
        }
        
        return ans;
    }
};


//Approach-2 (Using fixed size array to store frequency)
//T.C : O(n)
//S.C : O(501) ~ O(1)
class Solution {
public:
    int findLucky(vector<int>& arr) {
        int freq[501] = {0};

        for(int &num : arr) {
            freq[num]++;
        }

        for(int i = 500; i >= 1; i--) {
            if(freq[i] == i)
                return i;
        }

        return -1;
    }
};


//Approach-3 (Using bits to store frequency)
//T.C : O(n)
//S.C : O(1) in place
class Solution {
public:
    int findLucky(vector<int>& arr) {
        int n = arr.size();

        for(int &num : arr) {
            int val = (num & 65535);

            if(val <= n) {
                arr[val-1] += (1<<16); //65536, pow(2, 16)
            }
        }

        for(int val = n; val >= 1; val--) {
            if((arr[val-1] >> 16) == val) {
                return val;
            }
        }

        return -1;
    }
};
