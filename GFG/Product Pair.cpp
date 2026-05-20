class Solution {
  public:
    bool isProduct(vector<int>& arr, long long target) {
        // code here
        unordered_set<long long> seen;

        for (long long num : arr) {

            if (num == 0) {

                if (target == 0 && !seen.empty()) {
                    return true;
                }

                seen.insert(num);
                continue;
            }

            if (target % num != 0) {
                seen.insert(num);
                continue;
            }

            long long needed = target / num;

            if (seen.count(needed)) {
                return true;
            }

            seen.insert(num);
        }

        return false;
    }
};
