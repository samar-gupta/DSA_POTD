//Leetcode Link : https://leetcode.com/problems/count-the-number-of-substrings-with-dominant-ones

//Approach (Improving the brute force by skipping index j wherever possible)
//T.C : Worst case O(n^2), but since we skip indices we get O(n*sqrt(n))
//S.C : O(n)
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();

        vector<int> cumCountOne(n, 0);
        cumCountOne[0] = (s[0] == '1') ? 1 : 0;

        for(int i = 1; i < n; i++) {
            cumCountOne[i] = cumCountOne[i-1] + ((s[i] == '1') ? 1 : 0);
        }

        //[i...j] = cumCountOne[j] - cumCountOne[i-1];

        int result = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {

                int oneCount  = cumCountOne[j] - (i - 1 >= 0 ? cumCountOne[i-1] : 0);
                int zeroCount = (j - i + 1) - oneCount;

                if((zeroCount * zeroCount) > oneCount) {
                    //skip j to avoid waste indices
                    int wasteIndices = (zeroCount * zeroCount) - oneCount;
                    j += wasteIndices - 1;
                } else if((zeroCount * zeroCount) == oneCount) {
                    result += 1;
                } else { //(zeroCount * zeroCount) < oneCount
                    //[i....j] is a valid substring
                    result += 1;

                    //try to see how much j can shift to right until substring remains dominant
                    int k = sqrt(oneCount) - zeroCount;
                    int next = j + k;

                    if(next >= n) { //out of bound, means all indices are valid
                        result += (n - j - 1);
                        break; //early break
                    } else {
                        result += k;
                    }

                    j = next;
                }
            }
        }

        return result;

    }
};
