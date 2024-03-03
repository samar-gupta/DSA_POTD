class Solution{
public:
	// The main function that returns the arrangement with the largest value as string.
	// The function accepts a vector of strings
	
	static bool compare(const string &a, const string &b) {
        return (a + b) > (b + a);
    }
    
    string printLargest(int n, vector<string> &arr) {
        // code here
        sort(arr.begin(), arr.end(), compare);
        string result;
        for (int i = 0; i < n; ++i) {
            result += arr[i];
        }
        return result;
    }
};
