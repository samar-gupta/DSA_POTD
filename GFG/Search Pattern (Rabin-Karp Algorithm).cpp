//updated
// Approach: Rabin-Karp algorithm using rolling hash. Compute hash of pattern and compare it with rolling hash of substrings in text. If hashes match, verify with character comparison to avoid hash collision.
// Time Complexity: O(n + m) on average, where n = length of text and m = length of pattern; worst-case is O(nm) in case of hash collisions.
// Space Complexity: O(1) excluding result vector, as only a few variables are used for hashing.
class Solution {
public:
    // Helper function to compare pattern with substring of text at index idx
    bool isMatch(string& txt, string& pat, int idx) {
        for (int i = 0; i < pat.size(); i++) {
            if (txt[idx + i] != pat[i]) {
                return false;
            }
        }
        return true;
    }
    vector<int> search(string& pat, string& txt) {
        int m = pat.size();  // Length of pattern
        int n = txt.size();  // Length of text

        int base = 26;       // Base for hash (26 lowercase letters)
        int mod  = 101;      // A prime modulus to avoid overflow and reduce collisions

        vector<int> result;
        int         patHash = 0; // Hash value for pattern
        int         txtHash = 0; // Rolling hash value for text
        int         power   = 1; // Power of base (base^i)

        // Compute initial hash for pattern and first window of text
        for (int i = m - 1; i >= 0; i--) {
            int patVal = pat[i] - 'a' + 1;
            int txtVal = txt[i] - 'a' + 1;

            patHash = (patHash + patVal * power) % mod;
            txtHash = (txtHash + txtVal * power) % mod;
            power   = (power * base) % mod;
        }

        // Compare first window hash
        if (txtHash == patHash && isMatch(txt, pat, 0)) {
            result.push_back(1); // Store 1-based index
        }

        // Precompute highest power for sliding window (base^(m-1))
        int highestPower = 1;
        for (int i = 1; i < m; i++) {
            highestPower = (highestPower * base) % mod;
        }

        // Slide window across text
        for (int i = 1; i <= n - m; i++) {
            int leftVal = txt[i - 1] - 'a' + 1;

            // Remove leftmost character from hash
            txtHash = (txtHash - (leftVal * highestPower) % mod + mod) % mod;
            txtHash = (txtHash * base) % mod;

            // Add new character to hash
            int newVal = txt[i + m - 1] - 'a' + 1;
            txtHash = (txtHash + newVal) % mod;

            // If hashes match, verify with character comparison
            if (txtHash == patHash && isMatch(txt, pat, i)) {
                result.push_back(i + 1); // Store 1-based index
            }
        }

        return result;
    }
};


//old
class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
            vector<int>res;
            int q=101;
            int d=26;
            int M=pat.size();     //pattern
            int N=txt.size();
            int p=0;
            int t=0;
            int h=1;
            
            //h=pow(d,M-1)%q;
            for(int i=0;i<M-1;i++){
                h=(h*d)%q;
            }
            
            //calcualate the hash value of pattern and first window of text
            for(int i=0;i<M;i++){
                p=(d*p+pat[i])%q;
                t=(d*t+txt[i])%q;
            }
            
            //slide the pattern over thext one by one
            for(int i=0;i<=N-M;i++){
                //check the hash if they are equal
                if(p==t){
                    //check for characters one by one
                    int j=0;
                    for(j=0;j<M;j++){
                        if(txt[i+j]!=pat[j]){
                            break;
                        }
                    }
                    if(j==M){
                        res.push_back(i+1);
                    }
                    
                }
                if(i<N-M){
                    t=(d*(t-txt[i]*h)+txt[i+M])%q;
                    if(t<0){
                        t=t+q;
                    }
                }
            }
            
            return res;
        }
};
