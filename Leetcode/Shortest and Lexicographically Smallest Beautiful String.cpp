//Leetcode Link : https://leetcode.com/problems/shortest-and-lexicographically-smallest-beautiful-string

//Approach-1 (Brute Force)
//T.C : O(n^3)
//S.C : O(n), for temp string of length n
class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();

        for(int len = k; len <= n; len++) {

            string result = "";

            for(int start = 0; start + len <= n; start++) { //trying all possible substr of len
                string temp = s.substr(start, len); //[start ... start+len]

                int ones = 0;
                for (char ch : temp) {
                    ones += (ch == '1') ? 1 : 0;
                }

                // Keep it if it's beautiful and smaller than current best.
                if (ones == k) {
                    if (result.empty() || temp < result)
                        result = temp;
                }
            }
            
            //if we find result of k size, then it's smallest , no need to move to k++
            if(!result.empty())
                return result;
        }
        return "";
    }
};



//Approach-2 (Sliding Window)
//T.C : O(n^2)
//S.C : O(1)
class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();
        int i = 0;
        int ones = 0;     // number of '1's in window [i, j]
        string result = "";

        for (int j = 0; j < n; j++) {
            if (s[j] == '1') 
                ones++;

            //remove extra 1's, then trim leading 0's
            while (ones > k || s[i] == '0') {
                if (s[i] == '1') 
                    ones--;
                i++;
            }

            if (ones == k) {
                string temp = s.substr(i, j - i + 1);
                if (result.empty()
                    || j - i + 1 < result.length()
                    || (j - i + 1 == result.length() && temp < result)) {

                    result = temp;
                }
            }
        }

        return result;
    }
};
