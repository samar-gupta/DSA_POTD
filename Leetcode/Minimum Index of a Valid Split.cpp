//Leetcode Link : https://leetcode.com/problems/minimum-index-of-a-valid-split

//Approach-1 (Brute Force using 2 Maps)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> mp1; //stores elements of left subarray 
        unordered_map<int, int> mp2; //stores elements of right subarray

        for(int &num : nums) {
            mp2[num]++;
        }

        for(int i = 0; i < n; i++) {
            int num = nums[i];

            mp1[num]++;
            mp2[num]--;

            int n1 = i+1;
            int n2 = n-i-1;

            if(mp1[num]*2 > n1 && mp2[num]*2 > n2) {
                return i;
            }
        }

        return -1;
    }
};


//Approach-2 (Using Majority Element Concept)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();

        int maj   = -1;
        int count = 0;

        for(int i = 0; i < n; i++) {
            if(count == 0) {
                maj = nums[i];
                count = 1;
            } else if(nums[i] == maj) {
                count++;
            } else {
                count--;
            }
        }

        int majCount = 0;
        for(int &num : nums) {
            if(num == maj) {
                majCount++;
            }
        }

        count = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == maj) {
                count++;
            }

            int remainingCount = majCount - count;
            int n1 = i+1;
            int n2 = n-i-1;

            if(count*2 > n1 && remainingCount*2 > n2) {
                return i;
            }
        }


        return -1;

    }
};
