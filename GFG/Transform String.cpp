class Solution {
  public:
    int transform(string &s1, string &s2) {
        // code here
        int n = s1.size();

        if (n != (int)s2.size()) {
            return -1;
        }

        int freq[256] = {0};

        for (int i = 0; i < n; i++) {
            freq[(unsigned char)s1[i]]++;
            freq[(unsigned char)s2[i]]--;
        }

        for (int i = 0; i < 256; i++) {
            if (freq[i] != 0) {
                return -1;
            }
        }

        int i = n - 1;
        int j = n - 1;
        int operations = 0;

        while (i >= 0 && j >= 0) {
            if (s1[i] == s2[j]) {
                i--;
                j--;
            } else {
                operations++;
                i--;
            }
        }

        return operations;
    }
};
