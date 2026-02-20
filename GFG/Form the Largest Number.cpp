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



//Approach-1 :
class Solution {
  public:
    static bool compare(int a, int b){
        string s1 = to_string(a);
        string s2 = to_string(b);
        
        return s1 + s2 > s2 + s1;
    }
    
    string findLargest(vector<int> &arr) {
        // code here
        sort(arr.begin(), arr.end(), compare);
        string ans = "";
        
        for(auto &x : arr){
            ans += to_string(x);
        }
        return ans[0] == '0' ? "0" : ans;
    }
};
