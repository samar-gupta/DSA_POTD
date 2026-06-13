//Leetcode Link: https://leetcode.com/problems/weighted-word-mapping/description/

//Approach
//T.C : O(W * n), W = total words, n = average length of each word
//S.C : O(1) (Not considering space for result)
class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {

        string result = "";

        for (string &word : words) {

            int temp = 0;
            for (char& ch : word) {
                temp += weights[ch - 'a'];
            }

            result += 'z' - temp % 26;
        }

        return result;
    }
};
