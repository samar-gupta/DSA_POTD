//Company Tags  : GOOGLE, and some other company Online Assessment problem
//Leetcode Link : https://leetcode.com/problems/crawler-log-folder

//Approach-1 (Using simple simulation)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int minOperations(vector<string>& logs) {
        int depth = 0;

        for(string &s : logs) {
            if(s == "../") {
                depth = max(0, depth-1);
            } else if(s == "./") {
                continue;
            } else {
                depth++;
            }
        }

        return depth;
    }
};


//Approach-2 (Using Stack for simulation)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> st;

        for (const string& currentOperation : logs) {
            if (currentOperation == "../") {
                if (!st.empty()) {
                    st.pop();
                }
            } else if (currentOperation != "./") {
                st.push(currentOperation);
            }
        }

        return st.size();
    }
};
