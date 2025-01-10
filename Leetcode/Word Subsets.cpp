//Company Tags  : Amazon, Google
//Leetcode Link : https://leetcode.com/problems/word-subsets/

//Approach - (Simple storing character frequency in map and checking)
//T.C : O(n*l1 + m*l2) , n = # of words in words1, l1 = average length of word in words1, similarly m and l2 for words2
//S.C : O(26) ~= O(1)
class Solution {
public:
    bool isSubset(vector<int>& freq2, vector<int>& temp) {
        for(int i = 0; i < 26; i++) { //O(1)
            if(temp[i] < freq2[i]) {
                return false; //not a subset
            }
        }
        return true;
    }

    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> result;

        vector<int> freq2(26);
        //Total characters par iterate = O(n * l1)
        for(string &word : words2) { //O(n)
            int temp[26] = {0}; //vector<int> temp(26, 0)

            for(char &ch : word) { //O(l1)
                temp[ch-'a']++;

                freq2[ch-'a'] = max(freq2[ch-'a'], temp[ch-'a']);
            }
        }
        //O(m*l2)
        for(string &word : words1) { //O(m)
            vector<int> temp(26, 0);

            for(char &ch : word) { //O(l2)
                temp[ch-'a']++;
            }

            if(isSubset(freq2, temp) == true) { //O(1)
                result.push_back(word);
            }
        }

        //T.C : O(n*l1 m*l2) = overall saare characters of words1 and words2
        //S,C : O(26) ~= O(1)

        return result;
    }
};
