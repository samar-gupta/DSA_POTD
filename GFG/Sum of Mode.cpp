//Approach-1 : 
class Solution {
  public:
    int sumOfModes(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        int sum = 0;

        unordered_map<int, int> freq;

        auto cmp = [](const pair<int,int>& a, const pair<int,int>& b) {
            if (a.first != b.first) return a.first < b.first; 
            return a.second < b.second; 
        };

        set<pair<int,int>, decltype(cmp)> st(cmp);

        for (int i = 0; i < k; i++) {
            freq[arr[i]]++;
        }

        for (auto &x : freq) {
            st.insert({x.second, -x.first});
        }

        int mode = -st.rbegin()->second; 
        sum += mode;

        for (int i = k; i < n; i++) {
            int out = arr[i - k];
            int in = arr[i];

            int outFreq = freq[out];
            st.erase({outFreq, -out});

            freq[out]--;
            if (freq[out] > 0) {
                st.insert({freq[out], -out});
            } else {
                freq.erase(out);
            }

            freq[in]++;
            st.insert({freq[in], -in});

            mode = -st.rbegin()->second;
            sum += mode;
        }

        return sum;
    }
};
