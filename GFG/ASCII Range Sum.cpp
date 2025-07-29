//Approach-1 : 
//T.C : O(n)  //where n is the length of the string. We make only a few passes over the string, so it's linear
//S.C : O(1)  //We only use constant extra space (a few arrays of size 26 — one for each lowercase letter)
class Solution {
  public:
    vector<int> asciirange(string& s) {
        // code here
        // Arrays to store the first and last occurrence of each character
        vector<int> first(26, -1); // -1 means not found yet
        vector<int> last(26, -1);  // stores last occurrence
        vector<int> result;

        int n = s.length();

        // Step 1: Store first and last occurrence of each character
        for (int i = 0; i < n; ++i) {
            int idx = s[i] - 'a';
            if (first[idx] == -1) {
                first[idx] = i; // first time seeing this character
            }
            last[idx] = i; // keep updating last occurrence
        }

        // Step 2: Loop over all lowercase letters
        for (int c = 0; c < 26; ++c) {
            if (first[c] != -1 && last[c] != -1 && first[c] < last[c]) {
                // Sum ASCII values strictly between first and last
                int sum = 0;
                for (int i = first[c] + 1; i < last[c]; ++i) {
                    sum += (int)s[i];
                }
                if (sum > 0) {
                    result.push_back(sum);
                }
            }
        }

        return result;
    }
};
