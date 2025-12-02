//Approach :
/*
(Intuition) :
You start at index 0 in string s.
From a character s[i], you are allowed to jump forward to s[j] (j > i) if:
  1️⃣ There is a rule (s[i] → s[j]) in jumps
  2️⃣ OR s[i] == s[j] (self-jump allowed)
Whenever you jump i → j, the score added is:
  sum of ASCII values of all characters between i and j EXCEPT the target character s[j]
We want to maximize the total score after a sequence of valid jumps.

This is a Dynamic Programming + Recursion problem:
At every index, we choose the best possible next jump.
We store results so each index is solved once (memoization).


(Approach) :
Step 1: Add self-jumps
Each character can jump to itself always.

Step 2: Precompute next occurrence indexes
nextPos[i][c] = next index ≥ i where character c appears
→ Helps find jump destinations instantly.

Step 3: Prefix ASCII sum
pref[i] = sum of ASCII values of first i characters
→ Helps compute score between two indexes in O(1).

Step 4: DFS + DP
Let dp[i] = maximum score attainable starting from index i.
For each valid next character:
gain = score(i → j) dp[i] = max(dp[i], gain + dp[j])
Return dp[0].


(Dry Run Example) :
s = "forgfg" jumps = [['f','r'], ['r','g']]
Self jumps added automatically, so:

f→f, o→o, r→r, g→g also exist
Start at index 0: 'f'

Jump 1: f → r (index 2)
Characters between 0 and 2 = f, o
Exclude target r → none removed
📌 Score = 102 + 111 = 213

Jump 2: r → g (index 5)
Characters between 2 and 5 = r, g, f
Exclude target g → remaining r, f
📌 Score = 114 + 102 = 216

Total Score = 213 + 216 = 429 (maximum)


(Time & Space Complexity) :
Component             	Complexity
Building nextPos	-->   O(26 × n)
DFS + DP	        -->   O(26 × n)
Total Time	      -->   O(26 × n) ⇒ O(n)
Space	            -->   nextPos + pref + dp + adj = O(26 × n)
*/
class Solution {
public:
    int solve(int ind,string &s,vector<vector<int>> &adj,
              vector<int> &pref,vector<vector<int>> &nextPos,vector<int> &dp) {

        if(ind==s.size()-1){
            return 0;
        }
        
        if(dp[ind] != -1){
            return dp[ind];
        }

        int best=0;
        int curr=s[ind]-'a';

        // try every reachable target character
        for (int targetChar:adj[curr]){
            
            int jumpInd=nextPos[ind][targetChar - 'a'];
            
            if(jumpInd==-1){
                continue;
            }

            int gain;
            if (targetChar == s[ind]){
                // jump to same character → ignore its own ASCII
                gain=pref[jumpInd]-pref[ind+1];
            } 
            else{
                // jump to different character
                gain=pref[jumpInd]-pref[ind];
            }

            gain+=solve(jumpInd,s,adj,pref,nextPos,dp);
            best=max(best,gain);
        }

        return dp[ind]=best;
    }

    int maxScore(string &s, vector<vector<char>> &jumps) {
        int n=s.size();

        // allow self jumps for all characters
        for(char c = 'a'; c <= 'z'; c++){
            jumps.push_back({c, c});
        }
            

        // next index of each character from every index
        vector<vector<int>> nextPos(n,vector<int>(26, -1));
        vector<int> last(26, -1);
        
        for(int i=n-1;i>=0;i--){
            for(int c=0;c<26;c++){
                nextPos[i][c]=last[c];
            }
                
            last[s[i]-'a']=i;
        }

        // adjacency list for valid transitions char → char
        vector<vector<int>> adj(26);
        
        for (auto &p:jumps) {
            adj[p[0]-'a'].push_back(p[1]);
        }

        // prefix sum of ASCII values of characters
        vector<int> pref(n+1,0);
        for (int i=0;i<n; i++){
            pref[i+1]=pref[i]+s[i];
        }
            

        vector<int> dp(n, -1);
        return solve(0,s,adj,pref,nextPos,dp);
        
    }
};
