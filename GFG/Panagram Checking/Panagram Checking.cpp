//T.C : O(2n) ~ O(n)
//S.C : O(26) ~ O(1)
class Solution
{
  public:
    //Function to check if a string is Pangram or not.
    bool checkPangram (string s) {
        vector<int> arr(26, 0);
        
        for(char &ch : s) {
            if(ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z') {
                ch = tolower(ch);
                int index = ch - 'a';
                arr[index]++;
            }
        }
        
        for(int &count : arr) {
            if(count == 0)
                return false;
        }
        
        return true;
    }
};





//T.C : O(n)
//S.C : O(26) ~ O(1)
class Solution
{
  public:
    //Function to check if a string is Pangram or not.
    bool checkPangram (string s) {
        vector<int> arr(26, 0);
        int count = 0;
        
        for(char &ch : s) {
            if(ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z') {
                ch = tolower(ch);
                int index = ch - 'a';
                if(arr[index] == 0) {
                    arr[index]++;
                    count++;
                }
            }
        }
        
        return count == 26;
    }
};
