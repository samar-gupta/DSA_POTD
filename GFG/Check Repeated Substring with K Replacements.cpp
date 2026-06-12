class Solution {
  public:
    bool kSubstr(string &s, int k) {
        // code here
        int n = s.size();

        if (n % k != 0)
            return false;

        unordered_map<string, int> freq;

        for (int i = 0; i < n; i += k) {
            freq[s.substr(i, k)]++;
        }

        if (freq.size() == 1)
            return true;

        if (freq.size() > 2)
            return false;

        for (auto &it : freq) {
            if (it.second == 1)
                return true;
        }

        return false;
    }
};
