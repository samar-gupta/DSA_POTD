//Leetcode Link : https://leetcode.com/problems/maximum-score-words-formed-by-letters

//Approach : (Using simple backtracking)
//T.C : O(2^n) where n is the total number of words
//S.C : O(n)
class Solution {
public:
    int n;
    int maxScore;

    void solve(int i, vector<int>& score, vector<string>& words, int currScore, vector<int>& freq){
          
        maxScore = max(maxScore, currScore);

        if(i >= n)
            return;

        vector<int> tempFreq = freq;

        int j         = 0;
        int tempScore = 0;

        while(j < words[i].length()) {
            char ch = words[i][j];

            tempFreq[ch - 'a']--;
            tempScore += score[ch - 'a'];

            if(tempFreq[ch-'a'] < 0)
                break;

            j++;
        }

        //Take words[i]
        if(j == words[i].length()) { //It means we could form the word words[i]
            solve(i+1, score, words, currScore + tempScore, tempFreq);
        }

        //Not Take words[i]
        solve(i+1, score, words, currScore, freq);
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> freq(26, 0);

        for(char &ch : letters){
            freq[ch - 'a']++;
        }
        maxScore = INT_MIN;
        n        = words.size();

        solve(0, score, words, 0, freq);
        
        return maxScore;
    }
};
