//Approach-1 : 
class Solution {
  public:
    string largestSwap(string &s) {
        // code here
        int n = s.size();
        vector<int> last(10, -1);

        for (int i = 0; i < n; i++) {
            last[s[i] - '0'] = i;
        }

        for (int i = 0; i < n; i++) {
            for (int d = 9; d > s[i] - '0'; d--) {
                if (last[d] > i) {
                    swap(s[i], s[last[d]]);
                    return s;
                }
            }
        }
        return s;
    }
};
