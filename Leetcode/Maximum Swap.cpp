//Company Tags  : META
//Leetcode Link : https://leetcode.com/problems/maximum-swap

//Approach-1 (using space to store maxRight Indices)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num); //stoi 
        int n = s.length();

        vector<int> maxRight(n); //stores the index of max element to right

        maxRight[n-1] = n-1;
        for(int i = n-2; i >= 0; i--) {
            int rightMaxIdx = maxRight[i+1];
            int rightMaxElement = s[rightMaxIdx];

            maxRight[i] = (s[i] > rightMaxElement) ? i : rightMaxIdx;
        }

        for(int i = 0; i < n; i++) {
            int maxRightIdx = maxRight[i];
            int maxRightElement = s[maxRightIdx];
            if(s[i] < maxRightElement) {
                swap(s[i], s[maxRightIdx]);
                return stoi(s);
            }
        }

        return num;
    }
};


//Approach-2 (using constant space)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.length();

        vector<int> maxRight(10, -1); //0,1,2.....9

        for(int i = 0; i < n; i++) {
            int idx = s[i] - '0'; //'2' -'0' = 2
            maxRight[idx] = i;
        }

        for(int i = 0; i < n; i++) {
            char currChar = s[i];
            int currDigit = currChar - '0';

            for(int digit = 9; digit > currDigit; digit--) {
                if(maxRight[digit] > i) {
                    swap(s[i], s[maxRight[digit]]);
                    return stoi(s);
                }
            }
        }

        return num;
    }
};
