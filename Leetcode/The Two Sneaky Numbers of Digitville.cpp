//Leetcode Link : https://leetcode.com/problems/the-two-sneaky-numbers-of-digitville

//Approach-1 (Simple using map)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> result;
        unordered_map<int, int> mp;
        for (int &num : nums) {
            mp[num]++;
            if (mp[num] == 2) {
                result.push_back(num);
            }
        }
        return result;
    }
};


//Approach-2 (Using bit mask and XOR)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        //0....n-1
        int n = nums.size() - 2;

        int XOR = 0; //a^b

        for(int &num : nums) {
            XOR ^= num;
        }

        for(int num = 0; num <= n-1; num++) { //original list
            XOR ^= num;
        }

        int trailZeroCount = __builtin_ctz(XOR);
        int mask = 1 << trailZeroCount;

        int G1 = 0;
        int G2 = 0;


        for(int &num : nums) {
            if(num & mask) {
                G1 ^= num;
            } else {
                G2 ^= num;
            }
        }

        for(int num = 0; num <= n-1; num++) {
            if(num & mask) {
                G1 ^= num;
            } else {
                G2 ^= num;
            }
        }

        return {G1, G2};
    }
};
