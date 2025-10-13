//Leetcode Link : https://leetcode.com/problems/find-resultant-array-after-removing-anagrams/

/*4 MORE WAYS TO SOLVE THIS PROBLEM by doing Check Anagram question 
     1. sorting both s1, s2 and checking if they are equal
     2. using unordered map to store frequency 
     3. using array of size 26 for both and checking if their frequencies are equal as there are only lowercase alphabets 
     4. making hash value of s1 and comparing with hash value of s2
*/
//Approach (simple traverse and check)  (taking only one array of size 26)
//T.C : O(n*m)
//S.C : O(1)
class Solution {
public:
    bool checkAnagram(string &s1, string& s2) {
        int arr[26] = {0};

        for(char &ch : s1) {
            arr[ch-'a']++;
        }

        for(char &ch : s2) {
            arr[ch-'a']--;
        }
        
        for(int i = 0; i < 26; i++) {
            if(arr[i] != 0)
                return false;
        }

        return true;
    }
    vector<string> removeAnagrams(vector<string>& words) {
        int n = words.size();

        vector<string> result;

        result.push_back(words[0]);

        for(int i = 1; i < n; i++) {
            if(!checkAnagram(words[i], result.back())) {
                result.push_back(words[i]);
            }
        }

        return result;
    }
};
