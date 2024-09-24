//Leetcode Link : https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix

//Approach 1 - Brute Force
//T.C : O(m⋅log10M + n⋅log10N)
//S.C : O(m⋅log10M)
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> st;

        //123
        //st : {123, 12, 1, 12345, 1234, }
        for(int val : arr1) {
            while(!st.count(val) && val > 0) {
                st.insert(val);

                val = val/10;
            }
        }


        int result = 0; //LCP
        for(int num : arr2) {
            while(!st.count(num) && num > 0) {
                num /= 10;
            }

            if(num > 0) {
                result = max(result, static_cast<int>(log10(num)) + 1);
            }
        }

        return result;
    }
};



//Approach 2 - Using Prefix Tree (TRIE)
//T.C : O(m⋅d+n⋅d)
//S.C : O(m⋅d)
struct TrieNode {
    //char digit;
    TrieNode* children[10]; //0, 1, 2...9
};

class Solution {
public:

    TrieNode* getTrieNode() {
        TrieNode* node = new TrieNode();
        for(int i = 0; i < 10; i++) {
            node->children[i] = nullptr;
        }

        return node;
    }

    void insert(int num, TrieNode* root) {
        TrieNode* crawl = root;
        string numStr = to_string(num);

        for(char ch : numStr) {
            int idx = ch - '0';
            if(!crawl->children[idx]) {
                crawl->children[idx] = getTrieNode();
            }

            crawl = crawl->children[idx];
        }
    }

    //returns the length of th elongest prefix
    int search(int num, TrieNode* root) {
        TrieNode* crawl = root;
        string numStr = to_string(num);
        int length = 0;

        for(char ch : numStr) {
            int idx = ch - '0';
            if(crawl->children[idx]) {
                length++;
                crawl = crawl->children[idx];
            } else {
                break;
            }
        }

        return length;
    }

    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        TrieNode* root = getTrieNode(); //TRIE

        for(int num : arr1) {
            insert(num, root);
        }

        int result = 0;
        for(int num : arr2) {
            result = max(result, search(num, root));
        }

        return result;
    }
};
