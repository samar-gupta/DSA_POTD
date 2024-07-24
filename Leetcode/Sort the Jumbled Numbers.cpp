//Leetcode Link : https://leetcode.com/problems/sort-the-jumbled-numbers

//Approach-1 (Converting to string)
//T.C : O(n*d + nlogn) , Here, n is the size of the nums vector, and d is the average number of digits in the numbers.
//S.C : O(n+d)
class Solution {
public:

    string getMappedNum(string &num, vector<int>& mapping) {
        string mappedNum = "";
        for(int i = 0; i < num.length(); i++) {
            char ch   = num[i];
            mappedNum += to_string(mapping[ch-'0']);
        }
        return mappedNum;
    }

    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> vec;

        for(int i = 0; i < n; i++) {
            string numStr     = to_string(nums[i]);
            
            string mappedStr  = getMappedNum(numStr, mapping);

            int mappedNum     = stoi(mappedStr);

            vec.push_back({mappedNum, i});
        }

        sort(begin(vec), end(vec));
        vector<int> result;

        for(auto &p : vec) {
            int originalNumIdx = p.second;
            result.push_back(nums[originalNumIdx]);
        }
        return result;
    }
};



//Approach-2 (Without Converting to string)
//T.C : O(n*d + nlogn) , Here, n is the size of the nums vector, and d is the average number of digits in the numbers.
//S.C : O(n)
class Solution {
public:

    int getMappedNum(int num, vector<int>& mapping) {
        if(num < 10) {
            return mapping[num];
        }

        int mappedNum  = 0;
        int plaveValue = 1;

        while(num) {
            int lastDigit   = num%10;
            int mappedDigit = mapping[lastDigit];
            mappedNum      += plaveValue * mappedDigit;

            plaveValue *= 10;
            num       /= 10;
        }

        return mappedNum;

    }

    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> vec;

        for(int i = 0; i < n; i++) {
            int mappedNum = getMappedNum(nums[i], mapping);

            vec.push_back({mappedNum, i});
        }

        sort(begin(vec), end(vec));
        vector<int> result;

        for(auto &p : vec) {
            int originalNumIdx = p.second;
            result.push_back(nums[originalNumIdx]);
        }
        return result;
    }
};
