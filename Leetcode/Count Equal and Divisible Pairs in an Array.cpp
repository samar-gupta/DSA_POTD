//Leetcode Link : https://leetcode.com/problems/count-equal-and-divisible-pairs-in-an-array

//Approach-1 (Brute Force)
//T.C : O(n^2) 
//S.C : O(n)
class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int n = nums.size();
        int result = 0;

        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {

                if ((i * j) % k == 0 && nums[i] == nums[j]) {
                    result++;
                }
            }
        }
        return result;
    }
};


//Approach-2 (Slight better approach)
//T.C : O(n * (log(k) + sqrt(k)))
//S.C : O(n)
class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int n = nums.size();
        int result = 0;

        unordered_map<int, vector<int>> indicesMap;
        for(int i = 0; i < n; i++) {
            indicesMap[nums[i]].push_back(i);
        }

        //k = 36
        //1, 2, 3, 4, 5, 6
        unordered_set<int> div;
        for(int f = 1; f*f <= k; f++) { //O(sqrt(k))
            if(k%f == 0) {
                div.insert(f); //{1, 2, 3, 4, 6, 36, 18, 12, 9}
                div.insert(k/f);
            }
        }

        //O(n * (log(k) + sqrt(k)))
        for(auto& [num, indices] : indicesMap) {
            unordered_map<int, int> factorsMap;

            for(int i : indices) {
                int GCD = gcd(i, k); // T.C : log(k)
                int j   = k / GCD;

                result += factorsMap[j];

                for(int f : div) {
                    if(i % f == 0) {
                        factorsMap[f]++;
                    }
                }
            }
        }
        return result;
        
    }
};
