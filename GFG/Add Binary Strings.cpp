class Solution {
  public:
    string addBinary(string& A, string& B) {
        // your code here
        string str = "";
	int sum, Asum, Bsum, carry = 0;
	int i = A.length() - 1, j = B.length() - 1;
	    
	while(i != -1 || j != -1 || carry){
	    Asum = (i != -1)? A[i--] - '0': 0;
	    Bsum = (j != -1)? B[j--] - '0': 0;
	        
	    sum = carry + Asum + Bsum;
	    str += to_string(sum % 2);
	    carry = sum / 2;
	}
	j = str.length() - 1;
	while(str[j] != '1') { str.pop_back(); j--;}
	reverse(str.begin(), str.end());
	return str;
    }
};
