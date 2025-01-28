class Solution {
public:
    vector<string> findPermutation(string &s) {
        set<string> ans;
        vector<bool> visit(s.length(), false);
        makePermutation(s, ans, "", visit);
        return vector<string>(ans.begin(), ans.end());
    }

private:
    void makePermutation(const string &s, set<string> &ans, string curr, vector<bool> &visit) {
        if (curr.length() == s.length()) {
            ans.insert(curr);
            return;
        }
        for (int i = 0; i < s.length(); i++) {
            if (!visit[i]) {
                visit[i] = true;
                makePermutation(s, ans, curr + s[i], visit);
                visit[i] = false;
            }
        }
    }
};
