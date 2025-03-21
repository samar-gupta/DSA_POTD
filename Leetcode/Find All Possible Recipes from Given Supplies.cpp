//Leetcode Link : https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies

//Approach-1 - Brute Force
//T.C : (n^2 * m)
//S.C : O(n+S)
class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n = recipes.size();
        vector<string> result;

        unordered_set<string> st(begin(supplies), end(supplies));

        vector<bool> cooked(n, false);

        int count = n;
        while(count--) {

            for(int j = 0; j < n; j++) {
                if(cooked[j]) {
                    continue;
                }

                bool banpaega = true;
                for(int k = 0; k < ingredients[j].size(); k++) {
                    if(!st.count(ingredients[j][k])) {
                        banpaega = false;
                        break;
                    }
                }

                if(banpaega) {
                    st.insert(recipes[j]);
                    result.push_back(recipes[j]);
                    cooked[j] = true;
                }
            }
        }
        return result;
    }
};


//Approach-2 - Using Topological Sorting
//T.C : (n + m + S)
//S.C : O(n+S)
class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n = recipes.size();
        unordered_set<string> st(begin(supplies), end(supplies));

        //adj
        unordered_map<string, vector<int>> adj; //ing ---> recipe


        vector<int> indegree(n, 0);
        for(int i = 0; i < n; i++) {
            for(string& ing : ingredients[i]) {
                if(!st.count(ing)) {
                    adj[ing].push_back(i);
                    indegree[i]++;
                }
            }
        }

        queue<int> que;
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) {
                que.push(i);
            }
        }

        vector<string> result;
        while(!que.empty()) {
            int i = que.front();
            que.pop();
            string recipe = recipes[i];
            result.push_back(recipe);

            for(int &idx : adj[recipe]) {
                indegree[idx]--;
                if(indegree[idx] == 0) {
                    que.push(idx);
                }
            }
        }

        return result;
    }
};
