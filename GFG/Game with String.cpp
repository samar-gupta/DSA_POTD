//updated
// Approach 1: Count frequency of each character, use greedy strategy to always reduce the character with highest frequency (to minimize square sum).
// Time Complexity: O(k * log 26 + 26) ≈ O(k) as 26 is constant. Sorting 26-length freq array k times.
// Space Complexity: O(1) since frequency array is fixed size of 26.
class Solution {
public:
    int minValue(string& s, int k) {
        vector<int> freq(26, 0); // Frequency array for 26 lowercase letters

        // Count frequencies
        for (char ch : s) {
            freq[ch - 'a']++;
        }

        // Remove k characters greedily from the highest frequency char
        while (k--) {
            sort(freq.begin(), freq.end()); // Sort to bring max freq to end
            if (freq[25] == 0) {            // If all characters are removed
                break;
            }
            freq[25]--; // Remove one occurrence from highest freq char
        }

        int result = 0;
        for (int val : freq) {
            result += val * val; // Sum of squares of remaining frequencies
        }

        return result;
    }
};


// Approach 2: Use a max heap (priority queue) to always pick and reduce the character with the highest frequency first (greedy).
// Time Complexity: O(n + k*log 26) ≈ O(n + k) since heap size is constant (max 26).
// Space Complexity: O(26) = O(1) since only 26 lowercase letters.
class Solution {
public:
    int minValue(string& s, int k) {
        vector<int> freq(26, 0); // Frequency array for 26 lowercase letters

        // Count frequencies
        for (char ch : s) {
            freq[ch - 'a']++;
        }

        priority_queue<int> pq; // Max heap to always reduce highest freq

        // Push all non-zero frequencies to heap
        for (int f : freq) {
            if (f > 0) {
                pq.push(f);
            }
        }

        // Remove k characters from the highest freq char
        while (k-- && !pq.empty()) {
            int top = pq.top();
            pq.pop();
            if (top > 1) {
                pq.push(top - 1); // Push back after reducing
            }
        }

        int result = 0;
        while (!pq.empty()) {
            int val = pq.top();
            pq.pop();
            result += val * val; // Sum of squares of remaining frequencies
        }

        return result;
    }
};


// Approach 3: Use a bucket array to count how many characters have the same frequency,
// then reduce highest frequencies first (greedy) using frequency buckets.
// Time Complexity: O(n + k + maxi) where maxi is the maximum frequency in s.
// Space Complexity: O(1) since arrays used are bounded (constant size 26 and max frequency ≤ n).
class Solution {
public:
    int minValue(string& s, int k) {
        // Step 1: Count frequency of each character and get maximum frequency
        vector<int> alphaFreq(26, 0);
        int         maxi = 0;

        for (char ch : s) {
            alphaFreq[ch - 'a']++;
            maxi = max(maxi, alphaFreq[ch - 'a']);
        }

        // Step 2: Build a bucket array where index = frequency and value = count of chars with that freq
        vector<int> freq(maxi + 1, 0);
        for (int i = 0; i < 26; i++) {
            if (alphaFreq[i] > 0) {
                freq[alphaFreq[i]]++;
            }
        }

        int maxFreq = maxi;

        // Step 3: Reduce highest frequencies greedily
        while (k > 0 && maxFreq > 0) {
            int countAtMax = freq[maxFreq];

            if (countAtMax <= k) {
                k -= countAtMax;
                freq[maxFreq - 1] += countAtMax;
                freq[maxFreq]      = 0;
                maxFreq--;
            } else {
                freq[maxFreq]     -= k;
                freq[maxFreq - 1] += k;
                k = 0;
            }
        }

        // Step 4: Calculate sum of squares of remaining frequencies
        int result = 0;
        for (int i = 1; i <= maxi; i++) {
            result += i * i * freq[i];
        }

        return result;
    }
};



//old
//Approach-1 (Using unordered map)
class Solution{
public:
    int minValue(string s, int k){
        unordered_map<char,int> mp;
        int n = s.size();
        for(int i = 0;i<n;i++){
            mp[s[i]]++;
        }
        priority_queue<int> pq;
        for(it:mp){
            pq.push(it.second);
        }
        while(k--){
            int temp = pq.top();
            pq.pop();
            temp--;
            pq.push(temp);
        }
        int ans = 0;
        while(!pq.empty()){
            int temp = pq.top();
            pq.pop();
            ans+=temp*temp;
        }
        return ans;
    }
};



//Approach-2 (We can use vector of size 26, as given in question that string contains only lower case alphabet ~ O(26))
