//Company Tags  : UBER
//Leetcode Link : https://leetcode.com/problems/replace-words

//Approach : (Using normal hashset and generating all substrings)
//T.C : o(n*l + m*l^2) , n = number of words in the dictionary, m be the number of words in the sentence, and l be the average length of each word.
class Solution {
public:

    string findRoot(string& word, unordered_set<string>& st) {

        //try all length substring starting from 0th index
        for(int l = 1; l <= word.length(); l++) {
            string root = word.substr(0, l);
            if(st.count(root)) {
                return root;
            }
        }

        return word;
    }

    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> st(dictionary.begin(), dictionary.end());

        stringstream ss(sentence);
        string word;
        string result;

        while(getline(ss, word, ' ')) {
            result += findRoot(word, st) + " ";
        }

        result.pop_back();
        return result;
    }
};
