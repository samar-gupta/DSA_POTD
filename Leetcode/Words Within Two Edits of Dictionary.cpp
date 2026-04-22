//Leetcode Link : https://leetcode.com/problems/words-within-two-edits-of-dictionary

//Approach (Iterate and check)
//T.C : O(q * d * n), q = queries.size(), d = dictionary.size(), n = query[i].length()
//S.C : O(1)
class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries,
                                vector<string>& dictionary) {
        vector<string> result;

        for (string& query : queries) {
            
            for (string& s : dictionary) {
                int diff = 0;

                for (int i = 0; i < query.size(); i++) {
                    if (query[i] != s[i]) {
                        ++diff;
                    }

                    if(diff > 2)
                        break;
                }

                if (diff <= 2) {
                    result.push_back(query);
                    break;
                }
            }
        }
        return result;
    }
};
