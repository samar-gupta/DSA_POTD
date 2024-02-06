//Company Tags   : Amazon(mutiple times), Google, Uber, Facebook, Bloomberg, Yahoo, Goldman Sachs, Microsoft, Apple, Walmart Labs, Twilio, Affirm
//Leetcode Link  : https://leetcode.com/problems/group-anagrams/

//Approach-1 (Using Sorting)
//T.C : O(n*klog(k))  (n = size of input, k = maximum length of a string in the input vector)
//S.C : O(n*k)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();

        vector<vector<string>> result;

        unordered_map<string, vector<string>> mp;

        for(int i = 0; i < n; i++) {
            string temp = strs[i];

            sort(temp.begin(), temp.end());

            mp[temp].push_back(strs[i]);
        }

        for(auto it : mp) {
            result.push_back(it.second);
        }

        return result;
    }
};





//Approach-2  (Taking advantage of constraints as there are only lowercase alphabet letters)
//T.C : O(n*k)  (n = size of input, k = maximum length of a string in the input vector)
//S.C : O(n*k)

class Solution {
public:

    string generate(string &word) {
        int arr[26] = {0};

        for(char &ch : word) {
            arr[ch-'a']++;
        }

        string new_word = "";

        for(int i = 0; i<26; i++) {
            int freq = arr[i];

            if(freq > 0) {
                new_word += string(freq, i+'a');
            }
        }

        return new_word;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();

        unordered_map<string, vector<string>> mp;

        vector<vector<string>> result;

        for(int i = 0; i < n; i++) {
            string word = strs[i];

            string new_word = generate(word);

            mp[new_word].push_back(strs[i]);
        }

        for(auto &it : mp) {
            result.push_back(it.second);
        }

        return result;
    }
};
