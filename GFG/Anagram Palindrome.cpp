class Solution {
  public:
    bool canFormPalindrome(string &s) {
        // code here
        int freq[26] = {0};

        for (char ch : s) {
            freq[ch - 'a']++;
        }

        int oddCount = 0;

        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 != 0) {
                oddCount++;
            }

            if (oddCount > 1) {
                return false;
            }
        }

        return true;
    }
};
