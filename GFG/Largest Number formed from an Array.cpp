//Approach-1 :
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


//Approach-2 :
//T.C : O(nlogn)
//S.C : O(1) (I am ignoring the space taken by result of size n which we have to return
class Solution{
public:
	string printLargest(int n, vector<string> &arr) {
	    
	    auto myComparator = [](string &s1, string &s2) {
	        if(s1+s2 > s2+s1) {
	            return true;
	        }
	        return false;
	    };
	    
	    sort(begin(arr), end(arr), myComparator);
	    
	    string result = "";
	    for(string &s : arr) {
	        result += s;
	    }
	    
	    return result;
	}
};
