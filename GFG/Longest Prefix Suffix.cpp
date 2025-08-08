//Approach-1 : (Using Two Pointers)
//T.C : O(n)
//S.C : O(1)
class Solution {
  public:
    int getLPSLength(string &str) {
        // code here
        int p = 0;  // Prefix pointer
        int s = 1;  // Suffix pointer
        int cnt = 0;  // Count of matching prefix-suffix
        int pos = 1;  // Starting position of suffix
        int n = str.size();  // Length of the string

        while(p < n && s < n) {
            if(str[p] == str[s]) {
                cnt++;
                p++;
                s++;
            } else {
                cnt = 0;
                pos++;
                s = pos;
                p = 0;
            }
        }

        return cnt;
    }
};


//old
class Solution {
  public:
    int lps(string str) {
        // Your code goes here
        int i=0, count =0, k=1, j=1;
        while( i<str.length() && j < str.length()){
            if(str[i] == str[j]){
                i++;
                j++;
                count ++;
            }else{
                i=0;
                j=k;
                k++;
                count =0;
            }
        }
        return count;
    }
};
