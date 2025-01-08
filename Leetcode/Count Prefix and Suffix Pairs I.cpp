//Leetcode Link : https://leetcode.com/problems/count-prefix-and-suffix-pairs-i

//Approach-1 Brute Force
//T.C : O(n^2 * l)
//S.C : O(n^2 * l)
class Solution {
public:
    
    bool isPrefixAndSuffix(string &check, string &s) {
        int n = check.length();

        //We can use find() function as well
        string s1 = s.substr(0, n);
        string s2 = s.substr(s.length() - n, n);
        
        return s1 == check && s2 == check;
        
    }
    
    int countPrefixSuffixPairs(vector<string>& words) {
        auto lambda = [](string& s1, string& s2) {
            return s1.length() < s2.length();
        };
        
        //sort(begin(words), end(words), lambda);
        
        int count = 0;
        for(int i = 0; i < words.size()-1; i++) {
            for(int j = i+1; j < words.size(); j++) {
                if(words[i].length() <= words[j].length() && isPrefixAndSuffix(words[i], words[j])) {
                    count++;
                }
            }
        }
        
        return count;
    }
};


//Approach-2 - Using TRIE 
//T.C : ~O(n^2*l), n = number of words, l = average length of each word
//S.C : ~O(n*l), need to store all characters of words
struct trieNode {
    trieNode* children[26];
    bool isEndOfWord;
};

trieNode* getNode() {
    trieNode* newNode = new trieNode();
    newNode->isEndOfWord = false;
    for(int i = 0; i < 26; i++) {
        newNode->children[i] = NULL;
    }
    return newNode;
}

class Trie {
    public:
        trieNode* root;

        Trie() {
            root = getNode();
        }

        void insert(string word) {
            trieNode* pCrawl = root;
            for(int i = 0; i < word.length(); i++) {
                int idx = word[i] - 'a';
                if(pCrawl->children[idx] == NULL) {
                    pCrawl->children[idx] = getNode();
                }
                pCrawl = pCrawl->children[idx];
            }
            pCrawl->isEndOfWord = true;
        }

        bool searchPrefix(string prefix) {
            trieNode* pCrawl = root;
            for(int i = 0; i < prefix.length(); i++) {
                int idx = prefix[i] - 'a';
                if(pCrawl->children[idx] == NULL) {
                    return false;
                }
                pCrawl = pCrawl->children[idx];
            }

            return true;
        }
};

class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();

        int count = 0;

        for(int j = 0; j < n; j++) {
            Trie prefixTrie; //calls constrctor
            Trie suffixTrie; //calls constructor

            prefixTrie.insert(words[j]);
            string reversed = words[j];
            reverse(begin(reversed), end(reversed));

            suffixTrie.insert(reversed);

            for(int i = 0; i < j; i++) {
                if(words[i].length() > words[j].length()) {
                    continue;
                }

                string rev = words[i];
                reverse(begin(rev), end(rev));

                if(prefixTrie.searchPrefix(words[i]) == true && suffixTrie.searchPrefix(rev) == true) {
                    count++;
                }
            }
        }

        return count;
    }
};
