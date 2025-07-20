//Approach : Number of n-digit numbers formed by including atleast one number from the `array`
//              = Total n-digits number formed - Total n-digit numbers formed by exlcuding all the numbers from `array`
//          This is called inclusion-exclusion principle
//          |A U B| = |A| + |B| - |A∩B|
class Solution {
  public:
    int countValid(int n, vector<int>& arr) {
        // code here
        int total = 9*pow(10, n-1);
        set<int> digits(arr.begin(), arr.end());
        int firstDigit;
        if(digits.count(0)) {
            firstDigit = 10 - digits.size();
        }
        else {
            firstDigit = 9 - digits.size();
        }
        return total - (firstDigit * pow(10 - digits.size(), n-1));
    }
};


//Approach-1 : 
class Solution {
  public:
    int countValid(int n, vector<int>& arr) {
        // code here
        int x = 9 * pow(10, n - 1);
        int s = arr.size();
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] == 0) s--;
        }
        int a = 10 - arr.size();
        int y = (9 - s) * pow(a, max(0, n - 1));
        return x - y;
    }
};
