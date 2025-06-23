//updated
// Approach 1: Sort the array and distribute digits alternatively to form two numbers such that smaller digits come at higher places. Then, add the two numbers using string addition to avoid integer overflow.
// Time Complexity: O(n log n), due to sorting of the array.
// Space Complexity: O(n), for storing the two strings and the result.
class Solution {
public:

    // Helper function to add two numbers represented as strings
    string addString(string& s1, string& s2) {
        int    i      = s1.length() - 1; // pointer for s1
        int    j      = s2.length() - 1; // pointer for s2
        int    c      = 0;               // carry
        string result = "";              // to store result

        // Loop till both strings and carry are processed
        while (i >= 0 || j >= 0 || c > 0) {
            int sum = c;  // initialize with carry

            if (i >= 0) {
                sum += (s1[i] - '0');  // add digit from s1 if exists
            }

            if (j >= 0) {
                sum += (s2[j] - '0');  // add digit from s2 if exists
            }

            result.push_back(sum % 10 + '0'); // add current digit
            c = sum / 10;                     // update carry
            i--; j--;                         // move pointers
        }

        // Remove leading zeros from the end
        while (!result.empty() && result.back() == '0') {
            result.pop_back();
        }

        // Reverse the result to get final number
        reverse(result.begin(), result.end());

        return result;
    }

    string minSum(vector<int>& arr) {
        sort(arr.begin(), arr.end()); // sort digits in ascending order

        string s1 = "";               // to build first number
        string s2 = "";               // to build second number

        for (int i = 0; i < arr.size(); i++) {
            if (i % 2 == 0) {
                s1.push_back(arr[i] + '0');  // alternate digits go to s1
            } else {
                s2.push_back(arr[i] + '0');  // rest go to s2
            }
        }

        return addString(s1, s2);  // return their sum
    }
};


// Approach 2: Count the frequency of digits using a frequency array. Then distribute the digits alternatively to two strings ensuring no leading zeros. Add the two numbers using string addition.
// Time Complexity: O(n + k), where n is the size of arr and k = 10 (fixed range of digits), sorting is not needed.
// Space Complexity: O(n), for storing the result strings.
class Solution {
public:

    // Helper function to add two numbers represented as strings
    string addString(string& s1, string& s2) {
        int    i      = s1.length() - 1;
        int    j      = s2.length() - 1;
        int    c      = 0;
        string result = "";

        while (i >= 0 || j >= 0 || c > 0) {
            int sum = c;

            if (i >= 0) {
                sum += (s1[i] - '0');
            }
            if (j >= 0) {
                sum += (s2[j] - '0');
            }

            result.push_back(sum % 10 + '0');
            c = sum / 10;
            i--;
            j--;
        }

        reverse(result.begin(), result.end());
        return result;
    }

    string minSum(vector<int>& arr) {
        vector<int> count(10, 0); // count array for digits 0–9

        for (int num : arr) {
            count[num]++;
        }

        string s1   = "";
        string s2   = "";
        bool   flag = true; // true -> insert in s1, false -> s2

        for (int digit = 0; digit < 10; digit++) {
            while (count[digit]--) {
                if (flag) {
                    if (!(s1.empty() && digit == 0)) {
                        s1.push_back(digit + '0'); // avoid leading 0
                    }
                    flag = false;
                } else {
                    if (!(s2.empty() && digit == 0)) {
                        s2.push_back(digit + '0');
                    }
                    flag = true;
                }
            }
        }

        return addString(s1, s2);
    }
};


//old
class Solution {
  public:
    string minSum(vector<int> &arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        string s1="";
        string s2="";
        for(int i=0;i<n;i++){
            if(i%2==0){
                s1+=to_string(arr[i]);
            }
            else{
                s2+=to_string(arr[i]);
            }
        }
        reverse(s1.begin(),s1.end());
        reverse(s2.begin(),s2.end());
        string ans="";
        int i=0;
        int carry=0;
        while(i<s1.size() || i<s2.size() || carry){
            int sum=0;
            if(i<s1.size())
            sum+=s1[i]-'0';
            if(i<s2.size())
            sum+=s2[i]-'0';
            sum+=carry;
            ans+=to_string(sum%10);
            carry=sum/10;
            i++;
        }
        while(ans.back()=='0'){
            ans.pop_back();
        }
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};
