//Approach-1 : 
//T.C : O(N*M) ,where N->Size of array, M-> longest string size   
//S.C : O(N) 
class Solution {
  public:
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    // Convert a string to net vowel-consonant balance
    int getBalance(const string& s) {
        int balance = 0;
        for (char ch : s) {
            if (isVowel(ch)) balance++;
            else balance--;
        }
        return balance;
    }

    int countBalanced(vector<string>& arr) {
        int n = arr.size();
        unordered_map<int, int> balanceFreq;
        balanceFreq[0] = 1; // empty prefix

        int res = 0;
        int prefixBalance = 0;

        for (int i = 0; i < n; ++i) {
            int current = getBalance(arr[i]);
            prefixBalance += current;

            // If this balance has been seen before, it means
            // subarray from that index to here is balanced
            res += balanceFreq[prefixBalance];

            balanceFreq[prefixBalance]++;
        }

        return res;
    }
};
