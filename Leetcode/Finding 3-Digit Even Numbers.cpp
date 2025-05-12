//Leetcode Link : https://leetcode.com/problems/finding-3-digit-even-numbers

//Approach-1 (Trying all possibilities using 3 for loops for 3 digits)
//T.C : O(n^3 + SlogS), S = total 3 digits even numbers
//S.C : O(S)
class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        unordered_set<int> st;
        int n = digits.size();

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                for(int k = 0; k < n; k++) {
                    if(i == j || j == k || i == k) {
                        continue;
                    }

                    int num = digits[i]*100 + digits[j] * 10 + digits[k];

                    if(num >= 100 && num%2 == 0) {
                        st.insert(num);
                    }
                }
            }
        }

        vector<int> result(begin(st), end(st));
        sort(begin(result), end(result));
        return result;
    }
};


//Approach-2 (Smartly finding valid digits for each position)
//T.C : O(1)
//S.C : O(1)
class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> result;
        vector<int> mp(10, 0);

        for(int &digit : digits) {
            mp[digit]++;
        }

        for(int i = 1; i <= 9; i++) {
            if(mp[i] == 0) continue;
            mp[i]--;
            for(int j = 0; j <= 9; j++) {
                if(mp[j] == 0) continue;
                mp[j]--;
                for(int k = 0; k <= 8; k += 2) {
                    if(mp[k] == 0) continue;
                    mp[k]--;

                    int num = i*100 + j*10 + k;
                    result.push_back(num);
                    mp[k]++;
                }
                mp[j]++;
            }
            mp[i]++;
        }
        return result;
    }
};
