//Approach-1 : 
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
  public:
    string findLargest(vector<int> &nums) {
        // code here
        vector<string> arr;
        for (int num : nums) {
            arr.push_back(to_string(num));
        }
        
        auto myComparator = [](const string &a, const string &b) {
            return (b + a) < (a + b);
        };

        sort(arr.begin(), arr.end(), myComparator);

        if (arr[0] == "0") return "0";

        string result;
        for (string &s : arr) {
            result += s;
        }

        return result;
    }
};
