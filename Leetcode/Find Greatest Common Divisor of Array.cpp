//Leetcode Link : https://leetcode.com/problems/find-greatest-common-divisor-of-array/description/

//Approach-1 : 
class Solution {
public:
    int findGCD(vector<int>& nums) {
        return __gcd(*min_element(nums.begin(), nums.end()), 
          *max_element(nums.begin(), nums.end()));
    }
};


//Approach-2 : 
class Solution {
public:
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }

        return a;
    }

    int findGCD(vector<int>& nums) {
        int mn = *min_element(nums.begin(), nums.end());

        int mx = *max_element(nums.begin(), nums.end());

        return gcd(mn, mx);
    }
};



//Approach-3 : 
class Solution {
public:
    int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    int findGCD(vector<int>& nums) {
        int mn = *min_element(nums.begin(), nums.end());

        int mx = *max_element(nums.begin(), nums.end());

        return gcd(mn, mx);
    }
};
