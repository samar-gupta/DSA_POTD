//Leetcode Link : https://leetcode.com/problems/count-the-hidden-sequences

//Approach - Using Maths for counting total possible shifts
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int curr = 0; //a[0] first element of hidden sequence
        int minVal = 0;
        int maxVal = 0;

        for(int &d : differences) {
            curr = curr + d;

            minVal = min(minVal, curr);
            maxVal = max(maxVal, curr);

            if((upper - maxVal) - (lower - minVal) + 1 <= 0) {
                return 0;
            }
        }

        return (upper - maxVal) - (lower - minVal) + 1;

    }
};
