//Company Tags  : Coursera, Quip
//Leetcode Link : https://leetcode.com/problems/special-binary-string

//Approach : (Recursion)
//T.C : ~O(n^2)
//S.C : O(n) stack space and to store special substrings
class Solution {
public:
    string makeLargestSpecial(string s) {
        vector<string> specials;

        int start = 0;
        int sum = 0;

        for(int i = 0; i < s.length(); i++) {
            sum += s[i] == '1' ? 1 : -1;

            if(sum == 0) {
                string inner = s.substr(start+1, i-start-1);
                specials.push_back("1" + makeLargestSpecial(inner) + "0");
                start = i+1;
            }
        }


        sort(begin(specials), end(specials), greater<string>());

        string result;
        for(string &str : specials) {
            result += str;
        }

        return result;    
    }
};
