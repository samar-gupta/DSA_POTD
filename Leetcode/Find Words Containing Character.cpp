//Leetcode Link : https://leetcode.com/problems/find-words-containing-character

//Approach (using c++ STL)
//T.C : O(m*n) 
//S.C : O(1)
class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> res;
        int n = words.size();
        for (int i = 0; i < n; ++i) {
            if (words[i].find(x) != string::npos) {
                res.push_back(i);
            }
        }
        return res;
    }
};


//Approach-2 : (using C++ STL)
//T.C : O(n × k)    , O(k) per word.
//S.C : O(1)
class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        int n = words.size();
        vector<int> result;
        auto lamda = [x](char ch){
            return (ch == x);
        };
        for(int i=0; i<n; i++){
            if(any_of(begin(words[i]), end(words[i]), lamda)== true){
                result.push_back(i);
            }
        }
        return result;
    }
};
