//Leetcode Link         : https://leetcode.com/problems/unique-3-digit-even-numbers/description/
//From Leetcode Qn Link : https://leetcode.com/problems/finding-3-digit-even-numbers/description/


//Approach : Same as Leetcode-2094, just return the count of elements for Leetcode-3483
class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int count = 0;
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
                    count++;
                    mp[k]++;
                }
                mp[j]++;
            }
            mp[i]++;
        }
        return count;
    }
};
