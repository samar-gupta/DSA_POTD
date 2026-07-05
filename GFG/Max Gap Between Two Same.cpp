class Solution {
  public:
    int maxCharGap(string &s) {
        // code here
        vector<int> firstPos(26, -1);

        int maxGap = -1;

        for (int i = 0; i < s.size(); i++) {
            int index = s[i] - 'a';

            if (firstPos[index] == -1) {
                firstPos[index] = i;
            } else {
                int gap = i - firstPos[index] - 1;

                maxGap = max(maxGap, gap);
            }
        }

        return maxGap;
    }
};
