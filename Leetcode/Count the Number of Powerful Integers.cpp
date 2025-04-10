//Leetcode Link : https://leetcode.com/problems/count-the-number-of-powerful-integers

//Approach (Using Simple String traversal and Combinatorics multipliaction to find count)
//T.C : O((n - m) * log(limit)), n and m are lengths of start and finish
//S.C : O(1)
class Solution {
public:
    long long solve(string& str, string& inputSuffix, int limit) {
        if(str.length() < inputSuffix.length()) {
            return 0;
        }

        long long count = 0;
        string trailString = str.substr(str.length() - inputSuffix.length()); //"00"
        //"3000" - 4
        //"12" - 2
        int remainL = str.length() - inputSuffix.length();

        for(int i = 0; i < remainL; i++) {
            int digit = str[i] - '0';

            if(digit <= limit) {
                count += digit * pow(limit+1, remainL-i-1);
            } else {
                count += pow(limit+1, remainL-i); //5^pos
                return count;
            }
        }

        if(trailString >= inputSuffix) {
            count += 1;
        }


        return count;

    }
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        string startStr = to_string(start-1);
        string finishStr = to_string(finish);

         return solve(finishStr, s, limit) - solve(startStr, s, limit);
    }
};
