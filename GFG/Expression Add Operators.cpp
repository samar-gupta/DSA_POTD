//Approach-1 :
class Solution {
  public:
    void solve(int index, string &num, int target, string curr, vector<string>& ans, long prev, long res) {
        if(index == num.length()) {
            if(res == target) {
                ans.push_back(curr);
            }
            return;
        }
        
        string st = "";
        long currRes = 0;
        
        for(int i = index; i < num.length(); i++) {
            if(i > index && num[index] == '0') break;
            
            st += num[i];
            currRes = currRes * 10 + (num[i] - '0');
            
            if(index == 0) {
                solve(i + 1, num, target, st, ans, currRes, currRes);
            } else {
                solve(i + 1, num, target, curr + "+" + st, ans, currRes, res + currRes);
                solve(i + 1, num, target, curr + "-" + st, ans, -currRes, res - currRes);
                solve(i + 1, num, target, curr + "*" + st, ans, prev * currRes, res - prev + (prev * currRes));
            }
        }
    }
    
    vector<string> findExpr(string &s, int target) {
        // code here
        vector<string> ans;
        solve(0, s, target, "", ans, 0, 0);
        return ans;
    }
};


//Approach-2 : 
class Solution {
  public:
    vector<string> ans;

    void dfs(string &s, int target, int idx, long long curVal, long long lastVal, string expr) {
        // Base case: reached end of string
        if (idx == s.size()) {
            if (curVal == target) {
                ans.push_back(expr);
            }
            return;
        }

        // Build numbers from idx to j
        for (int j = idx; j < s.size(); j++) {
            // Avoid numbers with leading zeros
            if (j > idx && s[idx] == '0') break;

            string part = s.substr(idx, j - idx + 1);
            long long num = stoll(part);

            if (idx == 0) {
                // First number, start expression
                dfs(s, target, j + 1, num, num, part);
            } else {
                // +
                dfs(s, target, j + 1, curVal + num, num, expr + "+" + part);

                // -
                dfs(s, target, j + 1, curVal - num, -num, expr + "-" + part);

                // *
                dfs(s, target, j + 1, curVal - lastVal + lastVal * num, lastVal * num, expr + "*" + part);
            }
        }
    }
    
    vector<string> findExpr(string &s, int target) {
        // code here
        ans.clear();
        dfs(s, target, 0, 0, 0, "");
        sort(ans.begin(), ans.end()); // lexicographically smallest order
        return ans;
    }
};
